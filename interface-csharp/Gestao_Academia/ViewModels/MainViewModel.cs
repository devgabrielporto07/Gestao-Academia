using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace Gestao_Academia.ViewModels;

public partial class MainViewModel : ViewModelBase
{
    [ObservableProperty]
   public partial ViewModelBase PaginaAtual {get; set;}= new AlunosViewModel();

   [RelayCommand]
   private void IrPara(string pagina)
    {
        PaginaAtual = pagina switch
        {
            "Alunos" => new AlunosViewModel(),
            "Planos" => new PlanosViewModel(),
            _ => PaginaAtual
        };
    }
}
