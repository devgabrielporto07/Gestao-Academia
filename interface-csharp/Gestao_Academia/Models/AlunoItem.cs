namespace Gestao_Academia.Models;

public record AlunoItem(
    int Id,
    string Nome,
    string Cpf,
    string Telefone,
    string Plano,
    string Situacao);