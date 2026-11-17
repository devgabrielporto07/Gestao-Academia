using CommunityToolkit.Mvvm.ComponentModel;
using System.Collections.ObjectModel;
using CommunityToolkit.Mvvm.Input;
using Gestao_Academia.Models;
using Gestao_Academia.Services;

namespace Gestao_Academia.ViewModels;

public partial class PlanosViewModel : ViewModelBase
{
    private readonly IPlanoService _service;


    [ObservableProperty] public partial PlanoItem? PlanoSelecionada {get; set; }
    [ObservableProperty] public partial PlanoItem? PlanoEscolhido {get; set; }
    [ObservableProperty]public partial string Mensagem {get; set;} = "";

    public ObservableCollection<PlanoItem> Planos {get;} = new();

    public PlanosViewModel(IPlanoService service)
    {
        _service = service;
        foreach (var plano in _service.Listar())
           Planos.Add(plano);
    }

    public PlanosViewModel() : this(new PlanoServiceFake()) { }

    [RelayCommand]
    private void Escolher()
    {
        if(PlanoSelecionada is null)
        {
            Mensagem = "Escolha Invalida: selecione um plano na tabela";
            return;
        }

        PlanoEscolhido = PlanoSelecionada;
        Mensagem = "Plano escolhido com Sucesso!";
    }
}