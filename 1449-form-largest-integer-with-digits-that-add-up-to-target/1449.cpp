class Solution {
public:
    int maxDigitos(vector<int>& custo, int indice, int somaAtual, vector<vector<int>>& pd, int alvo) {
        // Caso base: Custo atual excedeu o alvo
        if (somaAtual > alvo)
            return INT_MIN;

        // Caso base: Sem mais dígitos, verifica se a soma bate com o alvo
        if (indice < 0)
            return somaAtual == alvo ? 0 : INT_MIN;

        // Retorna o resultado se já foi calculado
        if (pd[indice][somaAtual] != -1)
            return pd[indice][somaAtual];

        // Incluir o dígito atual 
        int incluiu = INT_MIN;
        if (somaAtual + custo[indice] <= alvo) {
            incluiu = 1 + maxDigitos(custo, indice, somaAtual + custo[indice], pd, alvo);
        }

        // Não incluir o dígito atual
        int excluiu = maxDigitos(custo, indice - 1, somaAtual, pd, alvo);

        // Salva e retorna o melhor resultado 
        return pd[indice][somaAtual] = max(incluiu, excluiu);
    }

    void reconstruirResultado(vector<int>& custo, int indice, int somaAtual, vector<vector<int>>& pd, int alvo,
            string& numeroFormado) {
        if (somaAtual > alvo || indice < 0) {
            return;
        }

        // Simula as escolhas para ver qual levou ao resultado ótimo
        int incluiu = INT_MIN;
        if (somaAtual + custo[indice] <= alvo) {
            incluiu = 1 + maxDigitos(custo, indice, somaAtual + custo[indice], pd, alvo);
        }
        int excluiu = maxDigitos(custo, indice - 1, somaAtual, pd, alvo);
        
        // Se incluir o dígito é o melhor caminho 
        if (incluiu >= excluiu) {
            numeroFormado += char(indice + 1 + '0'); // Adiciona o dígito.
            // Continua a reconstrução a partir do novo estado.
            reconstruirResultado(custo, indice, somaAtual + custo[indice], pd, alvo, numeroFormado);
        } else {
            // Se não, apenas passa para o próximo dígito
            reconstruirResultado(custo, indice - 1, somaAtual, pd, alvo, numeroFormado);
        }
    }

    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();

        // Tabela de memoização
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int maximoDeDigitos = maxDigitos(cost, n - 1, 0, dp, target);

        if (maximoDeDigitos <= 0)
            return "0";

        string numero = "";
        reconstruirResultado(cost, n - 1, 0, dp, target, numero);

        return numero;
    }
};