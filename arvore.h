typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} Arvore;

Arvore *inserir(int valor, Arvore *raiz) {
    if (raiz) {
        //desviar ou para a esquerda ou para a direita
        if (valor <= raiz->dado) {
            //ir para esquerda
            raiz->esq = inserir(valor, raiz->esq);
        } else {
            //ir para direita
            raiz->dir = inserir(valor, raiz->dir);
        }
        return raiz;
    } else {
        //final da árvore ou região de nodos folhas = são nodos sem filhos
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
}

void exibirOrdenado(Arvore *raiz) {
    if (raiz) {
        exibirOrdenado(raiz->esq);
        cout << raiz->dado << "\t";
        exibirOrdenado(raiz->dir);
    }
}

int contar(Arvore *raiz) {
    if (raiz) {
        return 1 + contar(raiz->esq) + contar(raiz->dir);
    }
    return 0;
}

int contarFolhas(Arvore *raiz) {
    if (raiz) {
        if (!raiz->esq && !raiz->dir) {
            return 1;
        }
        return 0 + contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
    }
    return 0;
}

void mostrarFolhas(Arvore *raiz) {
    if (raiz) {
        mostrarFolhas(raiz->esq);

        if (!raiz->esq && !raiz->dir) {
            cout << raiz->dado << "\t";
        }
        mostrarFolhas(raiz->dir);
    }
}

bool localizar(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->dado) {
            return true;
        }
        if (valor < raiz->dado) { //vai para esquerda
            return localizar(valor, raiz->esq);
        }
        return localizar(valor, raiz->dir);
    }
    return false;
}

Arvore *podar(Arvore *raiz) {
    if (raiz) {
        //Verificar se é folha e podar
        if (!raiz->esq && !raiz->dir) {
            //podar
            free(raiz);
            return NULL;
        }
        //ir para esquerda
        raiz->esq = podar(raiz->esq);

        //ir para direita
        raiz->dir = podar(raiz->dir);
        return raiz;
    }
    return NULL; 
}

Arvore *deletar(Arvore *raiz) {
    if (raiz) {
        //ir para esquerda
        raiz->esq = deletar(raiz->esq);

        //ir para direita
        raiz->dir = deletar(raiz->dir);

        free(raiz);
    }
    return NULL;
}
