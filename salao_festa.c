#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>

void cadastro_cliente(FILE *arquivo);
void cadastro_do_funcionario(FILE *arquivo);
void cadastro_fornecedor(FILE *arquivo);
void cadastro_festa (FILE *arquivo);

/*REGISTRO PARA A DATA*/
struct data
{
    int dia;
    int mes;
    int ano;
};

/*REGISTRO PARA O CADASTRO DA FESTA*/
struct
{
    int codigo;
    char nome[50];
    int quant_convidados;
    struct data dt;
    char dia_da_semana[20];
    int inicio;
    int fim;
    char tema[50];
} festa;

/*REGISTRO PARA O ENDEREÇO*/
struct endereco
{
    char bairro[50];
    char rua[50];
    int num;
    char cidade[50];
    char estado[50];
    int cep;
};

/*REGISTRO PARA O CADASTRO DO CLIENTE*/
struct
{
    int codigo;
    char nome[50];
    struct endereco ender;
    int telefone;
    struct data date;
    int ultimo;
} cliente;

/*REGISTRO PARA O CADASTRO DO FUNCIONARIO*/
struct
{
    int codigo;
    char nome[50];
    float salario;
    int telefone;
    char funcao[50];
    char tipo[50];
} funcionario;

/*REGISTRO PARA O CADASTRO DO FORNECEDOR*/
struct
{
    int codigo;
    char nome[50];
    int telefone;
    char produto[50];
} fornecedor;

/*REGISTRO PARA O CADASTRO DO CONTRATO*/
struct
{
    int num_contrato;
    float valor_total;
    float desconto;
    float valor_final;
    char forma_pagamento;
    char status[20];
    char codigo_festa;

} contrato;


/*FUNÇÃO PRINCIPAL COM O MENU*/
int main()
{
    setlocale(LC_ALL,"portuguese");
    FILE *arquivo;
    if((arquivo = fopen("salao_festa.dat", "w+b"))==NULL)  /*ABRIR ARQUIVO BINARIO PARA LEITURA E ESCRITA*/
        if((arquivo = fopen("salao_festa.dat", "r+b"))==NULL)
        {
            printf("Erro ao abrir o arquivo!");
            exit(1);
        }

    int opcao;


    printf("\n------------  MENU --------------\n\n");
    printf("|    1- Cadastrar Cliente       |\n|\n|    2- Cadastrar Funcionario   |\n|\n|    3- Cadastrar Fornecedor    |\n|\n|    4- Cadastrar Festa         |\n|\n|    5- Pesquisa...             |\n|\n|    6- SAIR                    |\n|\n ---------------//--------------\n\n");
    scanf("%d", &opcao);
    int cont=0;

    switch(opcao)
    {
    case 1:
        cadastro_cliente(arquivo);
        break;
    case 2:
        cadastro_do_funcionario(arquivo);
        break;
    case 3:
        cadastro_fornecedor(arquivo);
        break;
    case 4:
        cadastro_festa(arquivo);
        break;

    case 5:
        pesquisa(arquivo);
        break;

    case 6:
        printf("Finalizando...");
        return 0;
        break;

    default:
        printf("Opção Invalida.\n");
        system("pause;");
        return main();
        system("cls");


    }
    getch();
    fclose(arquivo);
    return 0;
}


/*FUNÇÃO PARA CADASTRAR O CLIENTE*/

void cadastro_cliente(FILE *arquivo)
{


    setlocale(LC_ALL, "portuguese");
    int ultimo_cliente, codigo;
    if((arquivo = fopen("cliente.dat", "a+b"))==NULL)  /*ABRIR ARQUIVO BINARIO PARA LEITURA E ESCRITA  E ARMAZENAR OS DADOS DOS CLIENTES*/
    {
        if((arquivo = fopen("cliente.dat", "r+b"))==NULL)
        {
            printf("Erro ao abrir o arquivo!");
            exit(1);
        }
    }



    printf("Digite o codigo do cliente:");
    scanf("%d", &cliente.codigo);

    printf("\n\nDigite o nome do cliente:");
    scanf("%s", &cliente.nome);
    fflush(stdin);

    printf("\n\nDigite o endereço do cliente\n\nBairro:");
    scanf("%s", &cliente.ender.bairro);
    fflush(stdin);

    printf("\n\nRua:");
    scanf("%s", &cliente.ender.rua);
    fflush(stdin);

    printf("\n\nNº:");
    scanf("%d", &cliente.ender.num);

    printf("\n\nCidade:");
    scanf("%s", &cliente.ender.cidade);
    fflush(stdin);

    printf("\n\nEstado:");
    scanf("%s", &cliente.ender.estado);
    fflush(stdin);

    printf("\n\nCEP:");
    scanf("%d", &cliente.ender.cep);

    printf("\n\nTelefone:");
    scanf("%d", &cliente.telefone);

    printf("\n\nData de Nascimento\nDia:");
    scanf("%d", &cliente.date.dia);

    printf("\n\nMês:");
    scanf("%d", &cliente.date.mes);

    printf("\n\nAno:");
    scanf("%d", &cliente.date.ano);




    fseek(arquivo,0,SEEK_END);
    fwrite(&cliente, sizeof(cliente),1, arquivo);
    fclose(arquivo);

    printf("\n\n\n Cadastro Realizado com Sucesso!!\n\n");


    system("pause");
    system("cls");
    return main();


}




/*FUNÇÃO PARA ESCOLHER SE O FUNCIONARIO É FIXO OU TEMPORÁRIO*/

void cadastro_do_funcionario(FILE *arquivo)
{
    int escolha;
    printf("\nTipo:\n\n1- Temporário\n\n2- Fixo\n");
    scanf("%d", &escolha);
    if (escolha==1)
    {
        cadastro_do_funcionario_temporario(arquivo);
    }
    else if(escolha==2)
    {
        cadastro_do_funcionario_fixo(arquivo);
    }

    else
    {
        printf("nao e valido");
        return 0;
    }
}

/*FUNÇÃO PARA CADASTRAR O FUNCIONARIO FIXO*/

void cadastro_do_funcionario_fixo(FILE *arquivo)
{

    setlocale(LC_ALL, "portuguese");
    if((arquivo = fopen("funcionario_fixo.dat", "a+b"))==NULL)  /*ABRIR ARQUIVO BINARIO PARA ESCRITA E PARA ARMAZENAR OS DADOS DOS FUNCIONARIOS FIXO*/
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    int escolha;

    printf("\n\nDigite o Código do funcionario:");
    scanf("%d", &funcionario.codigo);


    printf("\n\nDigite o nome do funcionario:");
    scanf("%s", &funcionario.nome);
    fflush(stdin);

    printf("\n\nTelefone:");
    scanf("%d", &funcionario.telefone);


    printf("\n\nFunção:");
    scanf("%s", &funcionario.funcao);


    printf("\nSalário:");
    scanf("%f", &funcionario.salario);


    fseek(arquivo,0,SEEK_END);
    fwrite(&funcionario, sizeof(funcionario),1, arquivo);
    system("pause");
    fclose(arquivo);

    printf("\n\n\n Cadastro Realizado com Sucesso!!\n\n\n");

    system("pause");
    system("cls");
    return main();


}

/*FUNÇÃO PARA CADASTRAR O FUNCIONARIO TEMPORARIO*/

void cadastro_do_funcionario_temporario(FILE *arquivo)
{

    setlocale(LC_ALL, "portuguese");
    if((arquivo = fopen("funcionario_temporario.dat", "a+b"))==NULL)   /*ABRIR ARQUIVO BINARIO PARA ESCRITA E PARA ARMAZENAR OS DADOS DOS FUNCIONARIOS TEMPORARIO*/
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    int escolha;

    printf("\n\nDigite o Código do funcionario:");
    scanf("%d", &funcionario.codigo);

    printf("\nDigite o nome do funcionario:");
    scanf("%s", &funcionario.nome);
    fflush(stdin);

    printf("\nTelefone:");
    scanf("%d", &funcionario.telefone);


    printf("\nFunção:");
    scanf("%s", &funcionario.funcao);
    fflush(stdin);

    printf("\nSalário:");
    scanf("%f", &funcionario.salario);


    fseek(arquivo,0,SEEK_END);
    fwrite(&funcionario, sizeof(funcionario),1, arquivo);


    fclose(arquivo);


    printf("\n\n\n Cadastro Realizado com Sucesso!!\n\n\n");

    system("pause");
    system("cls");
    return main();


}

/*FUNÇÃO PARA CADASTRAR O FORNECEDOR*/

void cadastro_fornecedor(FILE *arquivo)
{

    setlocale(LC_ALL, "portuguese");
    if((arquivo = fopen("fornecedor.dat", "a+b"))==NULL)  /*ABRIR ARQUIVO BINARIO PARA ESCRITA E PARA ARMAZENAR OS DADOS DOS FORNECEDOR*/
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }


    printf("\n\nDigite o Código do Fornecedor:");
    scanf("%d", &fornecedor.codigo);

    printf("\nDigite o nome do fornecedor:");
    scanf("%s", &fornecedor.nome);
    fflush(stdin);

    printf("\nTelefone:");
    scanf("%d", &fornecedor.telefone);

    printf("\nProduto fornecido:");
    scanf("%s", &fornecedor.produto);
    fflush(stdin);

    fseek(arquivo,0,SEEK_END);
    fwrite(&fornecedor, sizeof(fornecedor),1, arquivo);

    fclose(arquivo);

    printf("\n\n\n Cadastro Realizado com Sucesso!!\n\n\n");

    system("pause");
    system("cls");
    return main();


}




/*FUNÇÃO PARA CADASTRAR A FESTA*/

void cadastro_festa(FILE *arquivo)
{
    setlocale(LC_ALL, "portuguese");
    int escolha, dia_da_semana,h,x=0,posicao;
    if((arquivo = fopen("cliente.dat", "r+b"))==NULL) /*ABRIR ARQUIVO BINARIO DO CLIENTE PARA LEITURA E CONFERIR SE O CLIENTE ESTA CADASTRADO*/
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    printf("Digite o Código do Cliente:");
    scanf("%d", &posicao);

    fseek(arquivo, sizeof(cliente)*(posicao-1), SEEK_SET);
    fread(&cliente,sizeof(cliente),1,arquivo);

    if(posicao==cliente.codigo)
    {
        printf("\n\nNome:%s\n\n", cliente.nome);

    }

    else
    {
        printf("Cliente não encontrado");

        return main();
    }


    fclose(arquivo);

    if((arquivo = fopen("festa.dat", "a+b"))==NULL) /*ABRIR ARQUIVO BINARIO PARA ESCREVER E ARMAZENAR DADOS DO CADASTRO DA FESTA*/


    {
        printf("arquivo nao encontado");
    }

    else
    {
        printf("Arquivo festa aberto\n\n");

    }

    fprintf(arquivo,"Nome do Cliente: %s\n\n", cliente.nome );

    printf("Digite o código da festa:");
    scanf("%d", &festa.codigo);

    printf("\n\nCódigo da festa: %d\n", festa.codigo);

    int op_quant; /*ESCOLHER EM UM PEQUENO MENU A QUANTIDADE DE CONVIDADOS*/

    printf("\n\n\n#  Quant.Convidados |   \n\n1-   30 Convidados  |\n\n2-   50 Convidados  | \n\n3-   80 Convidados  |  \n\n4-  100 Convidados  |\n\n");
    scanf("%d",&op_quant);
    if(op_quant==1)
    {
        festa.quant_convidados=30;
    }
    else if(op_quant==2)
    {
        festa.quant_convidados=50;
    }
    if(op_quant==3)
    {
        festa.quant_convidados=80;
    }
    else if(op_quant==4)
    {
        festa.quant_convidados=100;
    }

    printf("Quantidade de convidados: %d", festa.quant_convidados);

    int dia, mes;

    printf("\nData\n\nDia:");
    scanf("%d", &dia);

    printf("\n\nMês:");
    scanf("%d", &mes);

    fseek(arquivo, sizeof(festa), SEEK_SET);
    fread(&festa,sizeof(festa),1,arquivo);


    if(dia==festa.dt.dia && mes==festa.dt.mes)
    {
        printf("Data indisponivel");

    }

    else
    {
        festa.dt.dia=dia;
        festa.dt.mes=mes;
    }




    printf("\n\nAno:");
    scanf("%d", &festa.dt.ano);



    /*MENU PARA ESCOLHER O DIA DA SEMANA E HORÁRIO DA FESTA*/

    printf("\nEscolha o dia da semana:\n\n1- Domingo\n\n2- Segunda\n\n3- Terça\n\n4- Quarta\n\n5- Quinta\n\n6- Sexta\n\n7- Sábado");
    scanf("%d", &dia_da_semana);
    if(dia_da_semana==1)
    {
        printf("\n\nDigite o horário de inicio(ex.:digite(18)para 18:00h:");
        scanf("%d",&festa.inicio);
        festa.fim=festa.inicio+4;
        strcpy(festa.dia_da_semana,"Domingo");
    }
    else if(dia_da_semana==2)
    {
        printf("\n\nDigite o horário de inicio(ex.:digite(18)para 18:00h:");
        scanf("%d",&festa.inicio);
        festa.fim=festa.inicio+4;
        strcpy(festa.dia_da_semana,"Segunda");
    }
    if(dia_da_semana==3)
    {
        printf("\n\nDigite o horário de inicio(ex.:digite(18)para 18:00h:");
        scanf("%d",&festa.inicio);
        festa.fim=festa.inicio+4;
        strcpy(festa.dia_da_semana,"Terça");
    }
    if(dia_da_semana==4)
    {
        printf("\n\nDigite o horário de inicio(ex.:digite(18)para 18:00h:");
        scanf("%d",&festa.inicio);
        festa.fim=festa.inicio+4;
        strcpy(festa.dia_da_semana,"Quarta");
    }
    if(dia_da_semana==5)
    {
        printf("\n\nDigite o horário de inicio(ex.:digite(18)para 18:00h:");
        scanf("%d",&festa.inicio);
        festa.fim=festa.inicio+4;
        strcpy(festa.dia_da_semana,"Quinta");
    }
    if(dia_da_semana==6)
    {
        printf("\n\nDigite o horário de inicio(ex.:digite(18)para 18:00h:");
        scanf("%d",&festa.inicio);
        festa.fim=festa.inicio+4;
        strcpy(festa.dia_da_semana,"Sexta");
    }
    else if(dia_da_semana==7)
    {
        printf("\n\nEscolha o horário da festa:\n\n 1- 12:00h às 16:00h\n\n2- 18:00h às 22:00h\n");
        scanf("%d",&h);
        if(h==1)
        {
            festa.inicio=12;
            festa.fim=16;

        }
        else if(h==2)
        {
            festa.inicio=18;
            festa.fim=22;

        }
        strcpy(festa.dia_da_semana,"Sabado");
    }


    printf("\n\nDia da Semana:%s", festa.dia_da_semana);


    printf("\n\nHorário\n\nInicio:%d:00h", festa.inicio);


    printf("\n\nFim:%d:00h", festa.fim);


    printf("\n\nTema:");
    scanf("%s", &festa.tema);
    fflush(stdin);


    fseek(arquivo,0,SEEK_END);
    fwrite(&festa, sizeof(festa),1, arquivo);
    fclose(arquivo);


    printf("\n\n\n Cadastro Realizado com Sucesso!!\n\n\n");
    system("pause");

    cadastro_contrato(arquivo);
    system("pause");
    system("cls");
    return main();
}


/*FUNÇÃO PARA CADASTRAR O CONTRATO*/

void cadastro_contrato(FILE *arquivo)
{
    setlocale(LC_ALL, "portuguese");

    if(arquivo = fopen("contrato.dat", "a + b")==NULL)   /*ABRIR ARQUIVO BINARIO PARA ESCRITA E ARMAZENAR DADOS DO CONTRATO*/

    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }


    printf("\n\nDigite o número do contrato:");
    scanf("%d",&contrato.num_contrato);


    contrato.valor_total=valor_total();
    printf("\nValor total: R$ %4.2f\n\n\n", contrato.valor_total);

    contrato.valor_final=valor_final(&contrato.valor_total);
    printf("\nValor final é igual a: %4.2f\n", contrato.valor_final);

    strcpy(contrato.status,"a pagar");
    printf("\n\nStatus: %s", contrato.status);

    printf("\nDigite o código da Festa:");
    scanf("%d", &festa.codigo);

    fseek(arquivo,0,SEEK_END);
    fwrite(&contrato, sizeof(contrato),1, arquivo);


    fclose(arquivo);

    printf("\n\n\n Cadastro Realizado com Sucesso!!\n\n\n");

    system("pause");
    system("cls");
    return main();

}


/*FUNÇÃO QUER RETORNA O VALOR TOTAL DA FESTA PARA O CONTRATO*/

int valor_total()
{
    int opcao;
    float valor;
    setlocale(LC_ALL,"portuguese");
    printf("           CALCULAR VALOR TOTAL\n        __________________________");
    printf("\n\n\n#  Quant.Convidados |   Dia da semana\n\n1-   30 Convidados  |  Segunda a Quinta\n\n2-   30 Convidados  |  Sexta a Domingo\n\n3-   50 Convidados  |  Segunda a Quinta\n\n4-   50 Convidados  |  Sexta a Domingo\n\n5-   80 Convidados  |  Segunda a Quinta\n\n6-   80 Convidados  |  Sexta a Domingo\n\n7-  100 Convidados  |  Segunda a Quinta\n\n8-  100 Convidados  |  Sexta a Domingo\n\n");
    scanf("%d", &opcao);
    switch(opcao)
    {
    case 1:
        valor=1899.00;
        break;
    case 2:
        valor=2099.00;
        break;
    case 3:
        valor=2199.00;
        break;
    case 4:
        valor=2299.00;
        break;

    case 5:
        valor=3199.00;
        break;
    case 6:
        valor=3499.00;
        break;
    case 7:
        valor=3799.00;
        break;
    case 8:
        valor=3999.00;
        break;

    default:
        printf("Opção Invalida.\n");

    }

    getch();
    system("cls");

    return valor;

}

/*FUNÇÃO QUE RETORNA O VALOR FINAL DA FESTA PARA O CONTRATO*/

int valor_final( float *valor)
{
    setlocale(LC_ALL,"portuguese");
    int opcao;
    float total,desconto;
    printf("           CALCULAR VALOR FINAL\n        __________________________\n\n");
    printf("Escolha a forma de pagamento:\n\n  1- A vista\n  2- Duas vezes\n  3- Três vezes\n  4- Quatro ou mais vezes\n");
    scanf("%d",&opcao);

    if(opcao==1)
    {
        desconto=0.1*(*valor);
        total=*valor-desconto;
    }

    else if(opcao==2)
    {
        desconto=0.05*(*valor);
        total=*valor-desconto;
    }

    else if(opcao==3)
    {
        desconto=0.02*(*valor);
        total=*valor-desconto;
    }

    else if(opcao==4)
    {
        total=*valor;
    }

    else
    {
        printf("Opção Inválida...");
    }
    return total;

}

/*FUNÇÃO COM MENU PARA ESCOLHER O QUE PESQUISAR*/

void pesquisa(FILE *arquivo)
{
    setlocale(LC_ALL,"portuguese");
    int opcao,escolha;
    printf("\nO que você deseja pesquisar:\n\n1- Cliente\n\n2- Funcionários\n\n3- Fornecedores\n");
    scanf("%d", &opcao);

    if (opcao==1)
    {
        system("cls");
        pesquisa_cliente(arquivo);
    }

    if (opcao==3)
    {
        system("cls");
        pesquisa_fornecedores(arquivo);
    }

    else if(opcao==2)
    {
        printf("\nTipo:\n\n1- Temporário\n\n2- Fixo\n");
        scanf("%d", &escolha);
        if (escolha==1)
        {
            system("cls");
            pesquisa_funcionario_temporario(arquivo);
        }
        else if(escolha==2)
        {
            system("cls");
            pesquisa_funcionario_fixo(arquivo);
        }

    }

}


/*FUNÇÃO PARA PESQUISAR POR DADOS DE CLIENTE*/

void pesquisa_cliente(FILE *arquivo)
{
     if((arquivo = fopen("cliente.dat", "r+b"))==NULL)  /*ABRIR ARQUIVO BINARIO CLIENTE PARA LEITURA*/
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    int posicao;
    printf("Digite o Código do Cliente:");
    scanf("%d", &posicao);
    fseek(arquivo, sizeof(cliente)*(posicao-1), SEEK_SET);
    fread(&cliente,sizeof(cliente),1,arquivo);
    printf("\n\nNome:%s\n\nEndereço\n\nBairro:%s\n\nRua:%s\n\nNº:%d\n\nCidade:%s\n\nEstado:%s\n\nCEP:%d\n\nTelefone:%d\n\nData de Nascimento:%d/%d/%d\n\n", cliente.nome,cliente.ender.bairro,cliente.ender.rua,cliente.ender.num,cliente.ender.cidade,cliente.ender.estado,cliente.ender.cep,cliente.telefone, cliente.date.dia,cliente.date.mes,cliente.date.ano);

    fclose(arquivo);
    system("pause");
    system("cls");
    return main();

}

/*FUNÇÃO PARA PESQUISAR POR DADOS DE FUNCIONARIO FIXO*/

void pesquisa_funcionario_fixo(FILE *arquivo)
{
    if((arquivo = fopen("funcionario_fixo.dat", "r+b"))==NULL)   /*ABRIR ARQUIVO BINARIO FUNCIONARIO FIXO PARA LEITURA*/
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    int posicao;
    printf("Digite o Código do Funcionário:");
    scanf("%d", &posicao);
    fseek(arquivo, sizeof(funcionario)*(posicao-1), SEEK_SET);
    fread(&funcionario,sizeof(funcionario),1,arquivo);
    printf("\n\nNome:%s\n\nTelefone:%d\n\nFunção:%s\n\nSalário:%4.2f\n\n", funcionario.nome,funcionario.telefone, funcionario.funcao, funcionario.salario);

    fclose(arquivo);
    system("pause");
    system("cls");
    return main();


}

/*FUNÇÃO PARA PESQUISAR POR DADOS DE FUNCIONARIO TEMPORÁRIO*/

void pesquisa_funcionario_temporario(FILE *arquivo)
{
    setlocale(LC_ALL, "portuguese");
    if((arquivo = fopen("funcionario_temporario.dat", "r+b"))==NULL)  /*ABRIR ARQUIVO BINARIO FUNCIONARIO TEMPORARIO PARA LEITURA*/
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    int posicao;
    printf("Digite o Código do Funcionário:");
    scanf("%d", &posicao);
    fseek(arquivo, sizeof(funcionario)*(posicao-1), SEEK_SET);
    fread(&funcionario,sizeof(funcionario),1,arquivo);
    printf("\n\nNome:%s\n\nTelefone:%d\n\nFunção:%s\n\nSalário:%4.2f\n\n", funcionario.nome,funcionario.telefone, funcionario.funcao, funcionario.salario);

    fclose(arquivo);
    system("pause");
    system("cls");
    return main();

}

/*FUNÇÃO PARA PESQUISAR POR DADOS DE FORNECEDORES*/

void pesquisa_fornecedores(FILE *arquivo)
{
    setlocale(LC_ALL, "portuguese");
    if((arquivo = fopen("fornecedor.dat", "r + b"))==NULL)  /*ABRIR ARQUIVO BINARIO FORNECEDOR PARA LEITURA*/
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    int posicao;
    printf("Digite o Código do Fornecedor:");
    scanf("%d", &posicao);
    fseek(arquivo, sizeof(fornecedor)*(posicao-1), SEEK_SET);
    fread(&fornecedor,sizeof(fornecedor),1,arquivo);
    printf("\n\nNome:%s\n\nTelefone:%d\n\nProduto Fornecido:%s\n\n", fornecedor.nome,fornecedor.telefone, fornecedor.produto);

    fclose(arquivo);
    system("pause");
    system("cls");
    return main();


}

