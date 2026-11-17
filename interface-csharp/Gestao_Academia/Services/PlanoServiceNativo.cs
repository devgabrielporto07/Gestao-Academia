using System.Collections.Generic;
using Gestao_Academia.Models;
using Gestao_Academia.Native;

namespace Gestao_Academia.Services;

public class PlanoServiceNativo : IPlanoService
{
    public List<PlanoItem> Listar()
    {
        var lista = new List<PlanoItem>();

        for (int id= 1; id <= 100; id++)
        {
            string nome = AcademiaNative.Texto(AcademiaNative.plano_nome(id));
            if(nome == "")
              break;

            double valor = AcademiaNative.plano_valor(id);
            int duracao = AcademiaNative.plano_duracao(id);

            lista.Add(new PlanoItem(id, nome, valor, duracao));
        }
        return lista;
    }

    public int Cadastrar(string nome, double valor, int duracaoMeses) => Codigos.ERRO_INVALIDO;
    public int Remover(int id) => Codigos.ERRO_INVALIDO;
}