using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Gestao_Academia.Services;

namespace Gestao_Academia.ViewModels;

public partial class MainViewModel : ViewModelBase
{
    // Os serviços são criados UMA vez e reaproveitados.
    // Assim os dados não somem quando você troca de página.
    private readonly IAlunoService _alunoService = new AlunoServiceFake();

    [ObservableProperty]
    public partial ViewModelBase PaginaAtual { get; set; }

    public MainViewModel()
    {
        PaginaAtual = new AlunosViewModel(_alunoService);
    }

    [RelayCommand]
    private void IrPara(string pagina)
    {
        PaginaAtual = pagina switch
        {
            "Alunos" => new AlunosViewModel(_alunoService),
            "Planos" => new PlanosViewModel(),
            _ => PaginaAtual
        };
    }
}