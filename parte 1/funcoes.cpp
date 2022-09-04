#include "funcoes.hpp"

using namespace std;

void menu()
{
    cout << "____________________________________________________________________" << endl;
    cout << "| (1) Selecione para ler todas as posicoes de uma vez                |" << endl;
    cout << "| (2) Selecione para ler de uma posicao x ate y                      |" << endl;
    cout << "| (3) Selecione para trocar dois registros de posicao                |" << endl;
    cout << "| (4) Selecione para inserir novos registros                         |" << endl;
    cout << "| (5) Selecione para alterar todos os dados de um registro existente |" << endl;
    cout << "| (6) Seleciione para deletar um registro do arquivo                 |" << endl;
    cout << "| (7) Para finalizar a execucao                                      |" << endl;
    cout << "____________________________________________________________________" << endl;
}

void lerRegistros()
{
    ifstream paste;
    paste.open("paste.bin", ios::binary);

    if (paste)
    {
        paste.seekg(0, paste.end);
        int tam = paste.tellg();
        paste.seekg(0, paste.beg);

        int numero_registros = tam / sizeof(Call_911);

        Call_911 *registros = new Call_911[1];

		paste.seekg(0, paste.beg);

		for ( int i = 0; i < numero_registros; i++ )
		{
			if (registros[0].flag == 1)
			{
				paste.seekg(i * sizeof(Call_911), paste.beg);
				paste.read((char*)(&registros[0]), sizeof(Call_911));         
				
				cout << registros[0].id << endl;
				cout << registros[0].lat << endl;
				cout << registros[0].lgn << endl;
				cout << registros[0].desc << endl;
				cout << registros[0].zip << endl;
				cout << registros[0].title << endl;
				cout << registros[0].timeStamp << endl;
				cout << registros[0].twp << endl;
				cout << registros[0].addr << endl;
				cout << registros[0].e << endl;
				cout << "- - - - - - - - - - - - " << endl;
			}
			else
			{
				cout << "ARQUIVO DELETADO!" << endl;
				cout << "- - - - - - - - - - - - " << endl;
			}
		}
    }
    else
    {
        cout << "Erro na leitura do arquivo!" << endl;
    }
    paste.close();
    return;
}

void lerPos(int p1, int p2)
{
    ifstream paste;
    paste.open("paste.bin", ios::binary);

    if ( paste )
    {
        Call_911 *registros = new Call_911[1];

		for ( int i = p1; i < p2 + 1; i++ )
		{
			paste.seekg(i * sizeof(Call_911), paste.beg);
			paste.read((char*)(&registros[0]), sizeof(Call_911));         
			if (registros[0].flag == 1)
			{
				cout << registros[0].id << endl;
				cout << registros[0].lat << endl;
				cout << registros[0].lgn << endl;
				cout << registros[0].desc << endl;
				cout << registros[0].zip << endl;
				cout << registros[0].title << endl;
				cout << registros[0].timeStamp << endl;
				cout << registros[0].twp << endl;
				cout << registros[0].addr << endl;
				cout << registros[0].e << endl;
				cout << "- - - - - - - - - - - - " << endl;
			}
			else
			{
				cout << "ARQUIVO DELETADO!" << endl;
				cout << "- - - - - - - - - - - - " << endl;
			}
		}
    }
    else
    {
        cout << "Erro na leitura do arquivo!" << endl;
    }
	paste.close();
    return;
}

void alterarDados(int pos0, Call_911 New)
{

    fstream paste;
	paste.open("paste.bin",fstream::in | fstream::out | fstream::binary);

    if ( paste )
    {
        Call_911 *registros = new Call_911[1];

        paste.seekg(pos0 * sizeof(Call_911), paste.beg);
        paste.read((char*)(&registros[0]), sizeof(Call_911));

        if (registros[0].flag == 1)
        {
                cout << registros[0].id << endl;
                cout << registros[0].lat << endl;
                cout << registros[0].lgn << endl;
                cout << registros[0].desc << endl;
                cout << registros[0].zip << endl;
                cout << registros[0].title << endl;
                cout << registros[0].timeStamp << endl;
                cout << registros[0].twp << endl;
                cout << registros[0].addr << endl;
                cout << registros[0].e << endl;
                cout << "- - - - - - - - - - - - " << endl;
            New.id = pos0;
            paste.seekp(pos0 * sizeof(Call_911), paste.beg);
            paste.write((const char *) (&New), sizeof(Call_911));

            paste.seekg(pos0 * sizeof(Call_911), paste.beg);
            paste.read((char*)(&registros[0]), sizeof(Call_911));

                cout << registros[0].id << endl;
                cout << registros[0].lat << endl;
                cout << registros[0].lgn << endl;
                cout << registros[0].desc << endl;
                cout << registros[0].zip << endl;
                cout << registros[0].title << endl;
                cout << registros[0].timeStamp << endl;
                cout << registros[0].twp << endl;
                cout << registros[0].addr << endl;
                cout << registros[0].e << endl;
                cout << "- - - - - - - - - - - - " << endl;
        }
        else
        {   
            cout << "- - - - - - - - - - - - - - - - - - -" << endl;
            cout << "IMPOSSIVEL ALTERAR O DADO FOI EXCLUIDO" << endl;
            cout << "- - - - - - - - - - - - - - - - - - -" << endl;
        }

    }
    else
    {
        cout << "Erro na leitura do arquivo!" << endl;
    }
    cout << "sucesso" << endl;
    paste.close();
}


void alterarPos(int p1, int p2)
{

    fstream paste;
	paste.open("paste.bin", fstream::in | fstream::out | fstream::binary);

    Call_911 *registros = new Call_911[1];
    Call_911 *registros0 = new Call_911[1];



    paste.seekg(p1 * sizeof(Call_911), paste.beg);
    paste.read((char*)(&registros[0]), sizeof(Call_911));
    paste.seekg(p2 * sizeof(Call_911), paste.beg);
    paste.read((char*)(&registros0[0]), sizeof(Call_911));

    if (registros[0].flag == 1 and registros0[0].flag == 1)
    {

        registros[0].id = p2;
        paste.seekp(p2 * sizeof(Call_911), paste.beg);
        paste.write((const char *) (&registros[0]), sizeof(Call_911));

        registros0[0].id = p1;
        paste.seekp(p1 * sizeof(Call_911), paste.beg);
        paste.write((const char *) (&registros0[0]), sizeof(Call_911));
        

            cout << "TROCANDO" << endl;

            cout << "- - - - - - - - - - - - " << endl;
            cout << p1 << endl;
            cout << registros[0].lat << endl;
            cout << registros[0].lgn << endl;
            cout << registros[0].desc << endl;
            cout << registros[0].zip << endl;
            cout << registros[0].title << endl;
            cout << registros[0].timeStamp << endl;
            cout << registros[0].twp << endl;
            cout << registros[0].addr << endl;
            cout << registros[0].e << endl;
            cout << "- - - - - - - - - - - - " << endl;

            cout << "COM" << endl;

            cout << "- - - - - - - - - - - - " << endl;
            cout << p2 << endl;
            cout << registros0[0].lat << endl;
            cout << registros0[0].lgn << endl;
            cout << registros0[0].desc << endl;
            cout << registros0[0].zip << endl;
            cout << registros0[0].title << endl;
            cout << registros0[0].timeStamp << endl;
            cout << registros0[0].twp << endl;
            cout << registros0[0].addr << endl;
            cout << registros0[0].e << endl;
            cout << "- - - - - - - - - - - - " << endl;
    }
    else
    {
        cout << "Um dos arquivos foi deletado impossivel realizar a troca";
    }
	paste.close();
}

void inserirNovoRegistro(int posicaoInsercao, Call_911 New)
{
    //331740
    //330000

    fstream paste;
	paste.open("paste.bin",fstream::in | fstream::out | fstream::binary);

    paste.seekg(0, paste.end);
    int tam = paste.tellg();
    paste.seekg(0, paste.beg);
    int numero_registros = tam / sizeof(Call_911);

    Call_911 *registros = new Call_911[1];

    paste.seekg(posicaoInsercao * sizeof(Call_911), paste.beg);
	paste.read((char*)(&registros[0]), sizeof(Call_911));

    if (registros[0].flag == true)
    {
        for ( int i = numero_registros - 1; i >= posicaoInsercao; i-- )
        {
            paste.seekg(i * sizeof(Call_911), paste.beg);
            paste.read((char*)(&registros[0]), sizeof(Call_911));
            registros[0].id += 1;
            paste.seekp((i + 1) * sizeof(Call_911), paste.beg);
            paste.write((const char *) (&registros[0]), sizeof(Call_911));
        }
        New.id = posicaoInsercao;
        New.flag = true;
        paste.seekp(posicaoInsercao * sizeof(Call_911), paste.beg);
        paste.write((const char *) (&New), sizeof(Call_911));
    }
    else    
    {
        New.id = posicaoInsercao;
        New.flag = true;
        paste.seekp(posicaoInsercao * sizeof(Call_911), paste.beg);
        paste.write((const char *) (&New), sizeof(Call_911));
    }

	paste.close();
}

void deletar(int p_delete)
{
    fstream paste;
	paste.open("paste.bin",fstream::in | fstream::out | fstream::binary);

    if ( paste )
    {

        Call_911 *registros = new Call_911[1];

        paste.seekg(p_delete * sizeof(Call_911), paste.beg);
        paste.read((char*)(&registros[0]), sizeof(Call_911));

            cout << registros[0].id << endl;
            cout << registros[0].lat << endl;
            cout << registros[0].lgn << endl;
            cout << registros[0].desc << endl;
            cout << registros[0].zip << endl;
            cout << registros[0].title << endl;
            cout << registros[0].timeStamp << endl;
            cout << registros[0].twp << endl;
            cout << registros[0].addr << endl;
            cout << registros[0].e << endl;
            cout << "- - - - - - - - - - - - " << endl;

            registros[0].flag = false;

        paste.seekp(p_delete * sizeof(Call_911), paste.beg);
        paste.write((const char *)(&registros[0]), sizeof(Call_911));

    }
    else
    {
        cout << "Erro na leitura do arquivo!";
    }
    cout << "sucesso" << endl;
    paste.close();
}