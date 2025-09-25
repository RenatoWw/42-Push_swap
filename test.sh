#!/bin/bash

# --- Configuração ---
EXECUTABLE="./push_swap"
MAKE_CMD="make"
USE_VALGRIND=true # Mude para 'false' para desativar os testes de leak e rodar mais rápido

# Cores e Contadores
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
CYAN="\033[36m"
RESET="\033[0m"
PASSED_COUNT=0
FAILED_COUNT=0
TEST_COUNT=0

# --- Compilação ---
echo -e "${YELLOW}Compilando o projeto...${RESET}"
$MAKE_CMD -s # O -s torna o make silencioso
if [ ! -f "$EXECUTABLE" ]; then
    echo -e "${RED}Erro: O executável '$EXECUTABLE' não foi encontrado. Abortando.${RESET}"
    exit 1
fi
echo -e "${GREEN}Compilação bem-sucedida!${RESET}"
echo "-----------------------------------------------------"

# --- Função Auxiliar de Teste ---
run_test() {
    ((TEST_COUNT++))
    DESCRIPTION="$1"
    EXPECTED_RESULT="$2"
    shift 2
    
    # Etapa 1: Verificar a lógica do programa (saída e código de erro)
    PROGRAM_OUTPUT=$($EXECUTABLE "$@" 2>&1)
    EXIT_CODE=$?

    LOGIC_PASSED=false
    if [ "$EXPECTED_RESULT" == "OK" ]; then
        if [ $EXIT_CODE -eq 0 ] && [ "$PROGRAM_OUTPUT" != "Error" ]; then
            LOGIC_PASSED=true
        fi
    elif [ "$EXPECTED_RESULT" == "ERROR" ]; then
        if [ $EXIT_CODE -ne 0 ] && [ "$PROGRAM_OUTPUT" == "Error" ]; then
            LOGIC_PASSED=true
        fi
    fi

    if ! $LOGIC_PASSED; then
        echo -e "❌  ${RED}FAIL (Lógica):${RESET} $DESCRIPTION"
        if [ "$EXPECTED_RESULT" == "OK" ]; then
             echo -e "     -> Esperado: OK (código 0, sem 'Error') | Recebido: Código $EXIT_CODE, Saída: '$PROGRAM_OUTPUT'"
        else
             echo -e "     -> Esperado: ERROR (código != 0, saída 'Error') | Recebido: Código $EXIT_CODE, Saída: '$PROGRAM_OUTPUT'"
        fi
        ((FAILED_COUNT++))
        return
    fi

    # Etapa 2: Se a lógica passou e Valgrind está ativo, verificar leaks
    if $USE_VALGRIND; then
        VALGRIND_OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="valgrind.log" $EXECUTABLE "$@" 2>&1)
        if grep -q "no leaks are possible" valgrind.log; then
            echo -e "✅  ${GREEN}PASS:${RESET} $DESCRIPTION ${CYAN}(Lógica OK, Sem Leaks)${RESET}"
            ((PASSED_COUNT++))
        else
            echo -e "❌  ${RED}FAIL (Leaks):${RESET} $DESCRIPTION"
            echo -e "     -> Lógica OK, mas Valgrind detectou memory leaks. Veja 'valgrind.log' para detalhes."
            ((FAILED_COUNT++))
        fi
        rm -f valgrind.log
    else
        # Se Valgrind estiver desativado, o teste passa se a lógica passou
        echo -e "✅  ${GREEN}PASS:${RESET} $DESCRIPTION ${YELLOW}(Lógica OK, Leaks não verificado)${RESET}"
        ((PASSED_COUNT++))
    fi
}

# --- Execução dos Testes (mesmos testes de antes) ---

echo -e "${YELLOW}--- I. Casos Válidos (devem ser aceitos) ---${RESET}"
run_test "Simples Multi-Arg" OK 1 2 3
run_test "Simples Single-Arg" OK "1 2 3"
run_test "Negativos e Zero" OK -1 0 1 2 -3
run_test "Multi-Arg e Single-Arg" OK 1 2 3 "4 5 6" 7 8
# ... (cole o resto dos testes do script anterior aqui) ...
echo -e "\n${YELLOW}--- II. Casos de ERRO de Sintaxe (devem ser rejeitados) ---${RESET}"
run_test "Letra no meio de multi-arg" ERROR 1 a 2
run_test "Letra no meio de single-arg" ERROR "1 a 2"
run_test "Argumento não numérico" ERROR "hello"
run_test "Número com letra" ERROR "12a4"
run_test "Dois sinais '--'" ERROR --1
run_test "Dois sinais '-+'" ERROR -+1
run_test "Sinal no lugar errado '1+'" ERROR 1+
run_test "Apenas sinais" ERROR "+" "-"

echo -e "\n${YELLOW}--- III. Casos de ERRO de Valor (devem ser rejeitados) ---${RESET}"
run_test "Duplicado simples" ERROR 1 2 1
run_test "Duplicado com sinal" ERROR 1 +1 2
run_test "Duplicado em single-arg" ERROR "0 1 2 3 0"
run_test "Overflow (maior que int)" ERROR 2147483648
run_test "Underflow (menor que int)" ERROR -2147483649
run_test "Número gigante" ERROR 99999999999999999999
run_test "Zero duplicado" ERROR 0 1 0

echo -e "\n${YELLOW}--- IV. Edge Cases (casos extremos) ---${RESET}"
run_test "Argumento string vazio" ERROR ""
run_test "Argumento string com apenas espaços" ERROR "   "
run_test "Múltiplos argumentos string vazios" ERROR "" ""
run_test "Argumento com tabulação" ERROR "1\t2"


# --- Relatório Final ---
# ... (o resto do script, como o teste de "Nenhum Argumento" e o Relatório Final, pode ser mantido como estava) ...
echo "-----------------------------------------------------"
echo -e "${YELLOW}Relatório Final:${RESET}"
echo -e "Total de testes: $TEST_COUNT"
echo -e "${GREEN}Passaram: $PASSED_COUNT${RESET}"
echo -e "${RED}Falharam: $FAILED_COUNT${RESET}"
echo "-----------------------------------------------------"
exit $FAILED_COUNT