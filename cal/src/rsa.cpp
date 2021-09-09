/*
@authors Lucas Eduardo Rosa de Freitas
@authors Lucas Matheus Camilo  
*/ 


#include "rsa.hpp"

gmp_randclass *RSA::gerador_rand = new gmp_randclass(gmp_randinit_default);

RSA::RSA(unsigned int bits){
    this->p=0;
    this->q=0;
    this->chaves.privada.first = 0;
    this->chaves.privada.second = 0;
    this->chaves.publica.first = 0;
    this->chaves.publica.second = 0;
    this->bits = bits < 8 ? 8 : bits;
    this->setChaves();
}

RSA::~RSA(){
    delete(this->gerador_rand);
}

mpz_class RSA::gera_big_rand() {
    mpz_class min;
    mpz_ui_pow_ui(min.get_mpz_t(), 2, (this->bits/2-1));
    mpz_class max;
    mpz_ui_pow_ui(max.get_mpz_t(), 2, (this->bits/2));

    mpz_class rand = this->gerador_rand->get_z_range(max-min);

    return (min + rand);
}

void RSA::setChaves(){
    while(true){
        this->p = gera_big_rand();
        if(millerRabin(this->p, 10))
            break;
    }
    while(true){
        this->q = gera_big_rand();
        if(millerRabin(this->q, 10) && this->p != this->q)
            break;
    }
    
    const mpz_class n = this->p * this->q;
    const mpz_class totient = (p - 1) * ( q - 1 );
    mpz_class e = 0;

    //faca o loop enquanto "e" e "totient" nao sejam coprimos
    while(true) { //usa o algoritmo euclediano para verificar se os números são coprimos
        if(totient > 2)
            e = this->gerador_rand->get_z_range(totient - 2) + 2;
        else
            e = this->gerador_rand->get_z_range(totient) + 2;

        if(gcd(e,totient)==1) break;
    }

    mpz_class d= inversoModular(e,totient);

    this->chaves.publica = std::make_pair(mpz_class(e), mpz_class(n));
    this->chaves.privada = std::make_pair(mpz_class(d), mpz_class(n));

    std::cout << "O par de chaves gerado é:\n";
    std::cout << "\tPublica: (" << this->chaves.publica.first << ";" << this->chaves.publica.second << ")\n";
    std::cout << "\tPrivada: (" << this->chaves.privada.first << ";" << this->chaves.privada.second << ")\n";
}


// A complexidade do % é igual a da multiplicação por FFT. A mod 2N +1 can be formed with a normal N ×N → 2N bits multiply plus a subtraction, so an FFT and Toom-3 etc can be compared directly

mpz_class RSA::gcd(mpz_class a, mpz_class b) { //O(k * log k * log log k)
    mpz_class temp; //O(1)
    while(a != 0 && b != 0) { //O(k * log k * log log k)
        temp=a; //O(1)
        a = b; //O(1)
        b = temp % b; //O(k * log k * log log k)
    }
    return a == 0 ? b : a; //O(1)
}

mpz_class RSA::egcd(mpz_class b, mpz_class a) { //O(k* log^2 k * log log k)
    mpz_class b0 = b, t, q; //O(1)
	mpz_class x0 = 0, x1 = 1; //O(1)
	if (b == 1) return 1; //O(1)
	while (a > 1 && b != 0) { //O(k * log^2 k * log log k)
		q = a / b; 
		t = b, b = a % b, a = t; 
		t = x0, x0 = x1 - q * x0, x1 = t; //O(k * log k * log log k) multiplicacao de big int pelo Schönhage–Strassen
	}
	if (x1 < 0) x1 += b0; //O(1)
	return x1; //O(1)
}

mpz_class RSA::inversoModular(mpz_class a, mpz_class b){ //O(k * log^2 k * log log k)
    mpz_class inverso = egcd(b, a); //O(k * log^2 k * log log k)
    if (inverso < 1) //O(1)
        inverso += b; //O(1)

    return inverso; //O(1)
}

mpz_class RSA::exponenciacaoModular(const mpz_class base, const mpz_class expoente, const mpz_class modulo) { //O(log n)
    mpz_class resultado; //O(1)
    mpz_powm (resultado.get_mpz_t(), base.get_mpz_t(), expoente.get_mpz_t(), modulo.get_mpz_t()); //O(log k) devido a utilizacao do FFT (transformada de fourrier) para calculo com bignum. Se fosse utilizada um calculo ingenuo, a complexidade seria O(log^2 k) por se tratar de BIG INT.
    return resultado; //O(1)
}

bool RSA::millerRabin(const mpz_class valor, const size_t iteracoes){ // O(x log^2 k), onde x é a quantidade de iterações e k a quantidade de bits que o valor possui.
    // desconsiderar números negativos
    if(valor <= 1) //O(1)
        return false; //O(1)
    

    // considerando 2 e 3 como primos
    if(valor <= 3) return true; //O(1)

    // numeros pares nao sao primos
    if((valor & 1) == 0) { //O(1)
        return false; //O(1)
    }

    size_t s = 0; //O(1) // atribuição
    mpz_class m = valor - 1; //O(1) // atribuição
    // enquanto o valor m for par
    while ((m & 1) == 0) { //O(log(k)) // 
        s++;
        m >>= 1; // divide por 2 
        
    }


    // esse for tem a maior complexidade 
    for (size_t i = 0; i < iteracoes; i++) { // O(x log^2 k), onde x é a quantidade de iterações e k a quantidade de bits.
        const mpz_class y = this->gerador_rand->get_z_range(valor - 3) + 2; //O(1)
        mpz_class x = exponenciacaoModular(y, m, valor); // O(log n) = log^2 k bits 

        if (x == 1 || x == (valor - 1)) //O(1) // verificação
            continue; //O(1)
        else //O(1)
            return false; //O(1)
       
    }

    return true; //O(1)
}

void RSA::criptografarArquivo(){
    std::string mensagem = "";

    FILE *arquivoDescriptografado;
    arquivoDescriptografado =  fopen("arquivos/plaintext.txt", "r");

    if(!arquivoDescriptografado) {
        std::cout << "Erro na abertura do arquivo plaintext.txt\n";
        return;
    }

    FILE *arquivoCriptografado;
    arquivoCriptografado = fopen("arquivos/encriptado.dat", "wb");

    if(!arquivoCriptografado) {
        std::cout << "Erro na escrita do encriptado.dat\n";
        fclose(arquivoDescriptografado);
        return;
    }

    mpz_class resultado;
    char ch;

    std::cout << "Gerando o arquivo criptografado\n";
    while((ch = fgetc(arquivoDescriptografado)) != EOF) {
        mpz_class valor(ch);

        resultado = this->exponenciacaoModular(valor, std::get<0>(this->chaves.publica), std::get<1>(this->chaves.publica));

        mensagem += resultado.get_str(10);

        mpz_out_raw(arquivoCriptografado, resultado.get_mpz_t());
    }

    std::cout << "Arquivo gerado com sucesso!\n";
    std::cout << "A mensagem criptografada é: " << mensagem << "\n";

    fclose(arquivoDescriptografado);
    fclose(arquivoCriptografado);
}

void RSA::descriptografarArquivo(std::string dfile){ // O(m^2 + m log n)
    std::string mensagem = "", msgc="";

    FILE *arquivoCriptografado;
    arquivoCriptografado = fopen("arquivos/encriptado.dat", "rb");
    if(!arquivoCriptografado) {
        std::cout << "Erro na leitura do encriptado.dat\n";
        return;
    }

    FILE *arquivoDescriptografado;
    dfile = "arquivos/" + dfile;
    arquivoDescriptografado = fopen(dfile.c_str(), "w");
    if(!arquivoDescriptografado) {
        fclose(arquivoCriptografado);
        std::cout << "Erro na escrita do arquivo descriptografado.txt\n";
        return;
    }

    std::cout << "Gerando o arquivo descriptografado\n";
    std::string mensagem_cifrada="";
    while(!feof(arquivoCriptografado)){ //O(m^2 + m log n)
        mpz_class valor;
        mpz_inp_raw(valor.get_mpz_t(), arquivoCriptografado);
        if(feof(arquivoCriptografado)) break;

        mpz_class result = this->exponenciacaoModular(valor, std::get<0>(this->chaves.privada), std::get<1>(this->chaves.privada)); //O(log n)
        
        mensagem += (char)(mpz_get_ui(result.get_mpz_t()));

    }
    fwrite(mensagem.c_str(), mensagem.size(), 1, arquivoDescriptografado);

    std::cout << "Arquivo descriptografado com sucesso!\n";
    std::cout << "A mensagem é: " << mensagem << "\n";

    fclose(arquivoCriptografado);
    fclose(arquivoDescriptografado);
}

void RSA::bruteForce(){ //O(2^n)
    mpz_class g = 1, x = 5, n = std::get<1>(this->chaves.publica); // O(1) // atribuições
    while (g == 1) { // O(k) = O(2^n) // isso acontece no pior dos casos k vezxez
        g = gcd(x, n); //O(k * log k * log log k) // essa complexidade vem com a aplicação do FFT, ela é por causa dos big ints
        x += 2; // O(1)
    }
    breakFile(g, "bruteForce.txt"); //O(k * log^2 k * log log k) // Como 2^n tem complexidade maior do que essa do breakfile, fica O(2^n)
}

//Método de Pollard’ Rho
void RSA::bruteForceHeuristica(){ // O(2^n)
    const mpz_class n = std::get<1>(this->chaves.publica); //O(1)
    mpz_class x = this->gerador_rand->get_z_range(n-1); //O(1)
    mpz_class c = this->gerador_rand->get_z_range(std::get<1>(this->chaves.publica)-1); // O(1)
    mpz_class y = x, g = 1; // O(1)
    while (g == 1) {// O(k) = O(2^n), no pior caso tu vai executar k operações, sendo k o número de bits. deste modo, O(2^n) operacoes
        x = ((x*x) % n + c) % n; //O(k * log k * log log k), devido ao FFT
        y = ((y*y) % n + c) % n; //O(k * log k * log log k), devido ao FFT
        y = ((y*y) % n + c) % n; //O(k * log k * log log k), devido ao FFT
        g = gcd(abs(x-y),n); //O(k * log k * log log k)
    }
    breakFile(g,"bruteForceHeuristica.txt");
}

void RSA::breakFile(mpz_class g, std::string file_name){ //O(k * log^2 k * log log k)
    const mpz_class n = std::get<1>(this->chaves.publica); // O(1)
    mpz_class totiene = (g - 1) * ( n / g - 1); //O(k * log k * log log k) multiplicacao de big int pelo Schönhage–Strassen
    mpz_class d = inversoModular(std::get<0>(this->chaves.publica), totiene); //O(k * log^2 k * log log k)
    this->chaves.privada = std::make_pair(d, n); // O(1)
    std::cout << "File broken with success\n";
    descriptografarArquivo(file_name); 
}

void RSA::verificaArquivos(){
    unsigned int opcao = 0;
    std::string dfile="arquivos/";
    while(true){
        std::cout << "Digite uma opção para o arquivo a ser comparado\n";
        std::cout << "1- Descriptografia padrão\n";
        std::cout << "2- Brute Force\n";
        std::cout << "3- Bruteforce com heurística\n";
        std::cout << "::> ";

        std::cin >> opcao;

        if(opcao == 1) {
            dfile += "descriptografado.txt";
            break;
        } else if (opcao == 2) {
            dfile += "bruteForce.txt";
            break;
        } else if (opcao == 3) {
            dfile += "bruteForceHeuristica.txt";
            break;
        } else {
            std::cout << "Opcao desconhecida - Entre com um valor válido\n";
        }
    }

    std::ifstream f1("arquivos/plaintext.txt", std::ifstream::binary|std::ifstream::ate);
    std::ifstream f2(dfile, std::ifstream::binary|std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        std::cout<<"FALHA! Os aquivos são diferentes!\n";
        return;
    }

    if (f1.tellg() != f2.tellg()) {
        std::cout<<"FALHA! Os aquivos são diferentes!\n";
        return;
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    bool equals = std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
    equals ? 
        std::cout<<"SUCESSO! Os aquivos são iguais!\n" :
        std::cout<<"FALHA! Os aquivos são diferentes!\n";
}

void RSA::capturaTempo() {

    std::ofstream tempos("logs.tempos", std::ios::out | std::ios::app);

    if(!tempos.is_open()) {
        std::cout << "Erro na abertura do arquivo logs.tempos\n";
        return;
    }

    unsigned int opcao = 0;
    while(true){
        std::cout << "Digite uma opção para executar funcao\n";
        std::cout << "1- Geração das chaves\n";
        std::cout << "2- Processo de criptografia\n";
        std::cout << "3- Processo da descriptografia\n";
        std::cout << "4- Processo da Fatoração\n";
        std::cout << "5- Processo da Fatoração Heuristica\n";
        std::cout << "::> ";

        std::cin >> opcao;

        if(opcao == 1) {
            auto time_start = std::chrono::high_resolution_clock::now();
            for(size_t i = 0; i < 10; i++){
                this->setChaves();
            }            
            auto time_end = std::chrono::high_resolution_clock::now();
            auto time_span =  std::chrono::duration_cast<std::chrono::seconds>(time_end - time_start);
            tempos << "geraChaves;" << this->bits << ";" << (time_span.count()/10.0) << "\n";
            break;
        } else if (opcao == 2) {
            this->setChaves();
            auto time_start = std::chrono::high_resolution_clock::now();
            for(size_t i = 0; i < 10; i++){
                this->criptografarArquivo();
            }
            auto time_end = std::chrono::high_resolution_clock::now();
            auto time_span =  std::chrono::duration_cast<std::chrono::seconds>(time_end - time_start);
            tempos << "criptografar;" << this->bits << ";" << time_span.count() << "\n";
            break;
        } else if (opcao == 3) {
            this->setChaves();
            this->criptografarArquivo();
            auto time_start = std::chrono::high_resolution_clock::now();
            for(size_t i = 0; i < 10; i++){
                this->descriptografarArquivo();
            }          
            auto time_end = std::chrono::high_resolution_clock::now();
            auto time_span =  std::chrono::duration_cast<std::chrono::seconds>(time_end - time_start);
            tempos << "descriptografar;" << this->bits << ";" << time_span.count() << "\n";
            break;
        } else if (opcao == 4) {
            this->setChaves();
            this->criptografarArquivo();
            auto time_start = std::chrono::high_resolution_clock::now();
            for(size_t i = 0; i < 1; i++){
                this->bruteForce();
            }
            auto time_end = std::chrono::high_resolution_clock::now();
            auto time_span =  std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
            tempos << "bruteForce;" << this->bits << ";" << time_span.count() << "\n";
            break;
        } else if (opcao == 5) {
            this->setChaves();
            this->criptografarArquivo();
            auto time_start = std::chrono::high_resolution_clock::now();
            for(size_t i = 0; i < 1; i++){
                this->bruteForceHeuristica();
            }
            auto time_end = std::chrono::high_resolution_clock::now();
            auto time_span =  std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
            tempos << "bruteForceHeuristica;" << this->bits << ";" << time_span.count() << "\n";
            break;
        }  else {
            std::cout << "Opcao desconhecida - Entre com um valor válido\n";
        }
    }

    tempos.close();
}