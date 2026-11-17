using System.Globalization;

namespace Gestao_Academia.Models;

public record PlanoItem(int id, string Nome, double Valor, int DuracaoMeses)
{
    private static readonly  CultureInfo Brasil = new("pt-BR");

    public string ValorTexto => Valor.ToString("C", Brasil);

    public string DuracaoTexto => DuracaoMeses == 1 ? "1 mês" : $"{DuracaoMeses} meses";

    public string ValorMensalTexto => (Valor / DuracaoMeses).ToString("C",Brasil);
}