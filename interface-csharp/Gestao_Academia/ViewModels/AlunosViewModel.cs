using System;
using System.Collections.ObjectModel;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Gestao_Academia.Models;
using Gestao_Academia.Services;

namespace Gestao_Academia.ViewModels;

public partial class AlunosViewModel : ViewModelBase
{
    private readonly IAlunoService _service;

    // ----- Campos do formulário -----
    [ObservableProperty] public partial string Nome { get; set; } = "";
    [ObservableProperty] public partial string Cpf { get; set; } = "";
    [ObservableProperty] public partial string Telefone { get; set; } = "";

    // ----- Pesquisa, mensagem e linha selecionada -----
    [ObservableProperty] public partial string Pesquisa { get; set; } = "";
    [ObservableProperty] public partial string Mensagem { get; set; } = "";
    [ObservableProperty] public partial AlunoItem? AlunoSelecionado { get; set; }

    // ----- A lista que aparece na tabela -----
    public ObservableCollection<AlunoItem> Alunos { get; } = new();

    // Construtor usado pelo app: recebe o serviço de fora
    public AlunosViewModel(IAlunoService service)
    {
        _service = service;
        Carregar();
    }

    // Construtor usado só pelo preview do editor
    public AlunosViewModel() : this(new AlunoServiceFake()) { }

    [RelayCommand]
    private void Salvar()
    {
        int resultado = _service.Cadastrar(Nome, Cpf, Telefone);

        if (resultado > 0)
        {
            Mensagem = $"Aluno cadastrado com id {resultado}.";
            Limpar();
            Carregar();
        }
        else
        {
            Mensagem = TraduzirErro(resultado);
        }
    }

    [RelayCommand]
    private void Limpar()
    {
        Nome = "";
        Cpf = "";
        Telefone = "";
    }

    [RelayCommand]
    private void Remover()
    {
        if (AlunoSelecionado is null)
        {
            Mensagem = "Selecione um aluno na tabela.";
            return;
        }

        string nome = AlunoSelecionado.Nome;
        int resultado = _service.Remover(AlunoSelecionado.Id);

        Mensagem = resultado == Codigos.OK ? $"{nome} removido." : TraduzirErro(resultado);
        Carregar();
    }

    // Chamado sozinho toda vez que o texto da pesquisa muda
    partial void OnPesquisaChanged(string value)
    {
        Carregar();
    }

    // Busca os alunos no serviço e preenche a tabela (aplicando a pesquisa)
    private void Carregar()
    {
        Alunos.Clear();

        foreach (var aluno in _service.Listar())
        {
            bool combina = Pesquisa == ""
                || aluno.Nome.Contains(Pesquisa, StringComparison.OrdinalIgnoreCase)
                || aluno.Cpf.Contains(Pesquisa);

            if (combina)
                Alunos.Add(aluno);
        }
    }

    // Transforma o código de erro (igual ao do C) em uma frase
    private static string TraduzirErro(int codigo)
    {
        return codigo switch
        {
            Codigos.ERRO_INVALIDO  => "Preencha pelo menos nome e CPF.",
            Codigos.ERRO_DUPLICADO => "Já existe um aluno com esse CPF.",
            Codigos.ERRO_NAO_ACHOU => "Aluno não encontrado.",
            _                      => $"Erro desconhecido ({codigo})."
        };
    }
}