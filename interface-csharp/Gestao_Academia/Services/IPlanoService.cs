using System.Collections.Generic;
using Gestao_Academia.Models;

namespace Gestao_Academia.Services;

public interface IPlanoService
{
    List<PlanoItem> Listar();
    int Cadastrar(string nome, double valor, int duracaoMeses);
    int Remover(int id);
}