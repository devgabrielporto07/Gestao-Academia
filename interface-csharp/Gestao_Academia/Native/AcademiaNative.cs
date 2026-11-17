using System;
using System.Runtime.InteropServices;

namespace Gestao_Academia.Native;

internal static class AcademiaNative
{
    private const string Biblioteca = "academia";

    [DllImport(Biblioteca, CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr plano_nome(int id);

    [DllImport(Biblioteca, CallingConvention= CallingConvention.Cdecl)]
    public static extern double plano_valor(int id);

    [DllImport(Biblioteca, CallingConvention= CallingConvention.Cdecl)]
    public static extern int plano_duracao(int id);

    public static string Texto(IntPtr ponteiro)
    {
        return Marshal.PtrToStringUTF8(ponteiro) ?? "";
    }
}