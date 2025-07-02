class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& palavras) {
        unordered_set<string> conjunto_palavras(palavras.begin(), palavras.end());
        vector<string> resultado;
        // Testa cada palavra do dicionário
        for (const string& palavra : palavras) {
            int tamanho = palavra.size();
            vector<int> pd(tamanho + 1, 0);
            pd[0] = 1; // Caso base: uma string vazia é sempre válida

            for (int i = 0; i < tamanho; i++) {
                // Se não é possível formar o prefixo até 'i', não há como estendê-lo
                if (pd[i] == 0) continue;
                // Tenta encontrar uma palavra do dicionário começando em 'i'
                for (int j = i + 1; j <= tamanho; j++) {
                    // A substring não pode ser a própria palavra
                    if (j - i < tamanho) {
                        string sub = palavra.substr(i, j - i);
                        if (conjunto_palavras.count(sub)) {
                            pd[j] = 1; // Marca que o prefixo até 'j' é formável
                        }
                    }
                }
                // Se a palavra inteira foi formada, adiciona ao resultado e para de verificar
                if (pd[tamanho]) {
                    resultado.push_back(palavra);
                    break;
                }
            }
        }
        return resultado;
    }
};