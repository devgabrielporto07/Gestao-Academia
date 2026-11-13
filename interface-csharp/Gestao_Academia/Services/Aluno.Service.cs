using System.Collections.Generic;
using Gestao_Academia.Models;

namespace Gestao_Academia.Services;

public interface IAlunoService
{
    List<AlunoItem> Listar();

    int Cadastrar(string nome, string cpf, string telefone);

    int Remover(int id);
}