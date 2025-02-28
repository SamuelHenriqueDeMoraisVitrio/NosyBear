
-- Definição das funções
function soma(a, b)
    return a + b
end

function subtracao(a, b)
    return a - b
end

function multiplicacao(a, b)
    return a * b
end

-- Tabela com as funções registradas
tabela_principal = {
    { arg = "soma", func = soma },
    { arg = "subtracao", func = subtracao },
    { arg = "multiplicacao", func = multiplicacao }
}

-- Função para buscar e executar a função correspondente
function executar_funcao(argumento, ...)
    for _, item in ipairs(tabela_principal) do
        if item.arg == argumento then
            return item.func(...)
        end
    end
    return nil, "Função não encontrada"
end

-- Testando
print(executar_funcao("soma", 5, 3))          -- 8
print(executar_funcao("subtracao", 10, 4))    -- 6
print(executar_funcao("multiplicacao", 6, 7)) -- 42
