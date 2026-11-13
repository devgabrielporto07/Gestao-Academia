using System.Collections.Generic;
using Gestao_Academia.Models;

namespace Gestao_Academia.Services;

public class AlunoServiceFake : IAlunoService
{
    private readonly  List<AlunoItem> _alunos = new()
    {
      new(1, "João Pereira",  "111.222.313-31", "(83) 9913-2314", "Anual",   "Em dia"),
      new(2, "Ana Lima",      "443.441.133-20","(83) 9242-5636", "Mensal",   "Pendente"),
      new(3, "Carlos lima",   "313.459.531-01", "(83) 9842-5632", "Trimestral",  "Em dia"),
      new(4, "Maria Luisa",   "222.667.448-90", "(83) 97424-5632", "-",     "Sem matricula"),
      new(5, "Rafael Silva",  "444.111.445-24", "(83) 9942-1441", "Anual",    "Em dia"),
    };

    private int _proximoId = 6;

    public List<AlunoItem> Listar()
    {
        return new List<AlunoItem>(_alunos);
    }

    public int Cadastrar(string nome, string cpf, string telefone)
    {
        if(string.IsNullOrWhiteSpace(nome) || string.IsNullOrWhiteSpace(cpf))
        return Codigos.ERRO_INVALIDO;
        {
            foreach (var aluno in _alunos)
            {
                if(aluno.Cpf == cpf.Trim())
                        return Codigos.ERRO_DUPLICADO;
            }

            var novo = new AlunoItem(_proximoId, nome.Trim(), cpf.Trim(), telefone.Trim(),
                                 "-", "Sem matrícula");
        _alunos.Add(novo);
        _proximoId++;
        return novo.Id;
        }
    }

    public int Remover(int id)
    {
        int removidos = _alunos.RemoveAll(aluno => aluno.Id == id);
        return removidos > 0 ? Codigos.OK : Codigos.ERRO_NAO_ACHOU;
    }
}