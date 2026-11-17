using System.Collections.Generic;
using Gestao_Academia.Models;

namespace Gestao_Academia.Services;

public class PlanoServiceFake : IPlanoService
{
    private readonly List<PlanoItem> _planos = new()
    {
        new(1, "Mensal",   100.00,  1),
        new(2, "Trimensal", 270.00, 3),
        new(3,"Semestral", 510.00, 6),
        new(4, "Anual", 960.00, 12),
    };

    public List<PlanoItem> Listar() => new List<PlanoItem>(_planos);

    public int Cadastrar(string nome,double valor, int duracaoMeses) => Codigos.ERRO_INVALIDO;
    public int Remover(int id) => Codigos.ERRO_INVALIDO;
}