using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Steamhook
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Logger.Server.StartConsole();
            Logger.Client.StartConsole();

            var injector = new Injector();

            int pid = injector.QueryUserForProcess();
            if(pid == -1)
            {
                Logger.Server.DebugLine("User cancelled process selection.");
            }
            else
            {
                injector.InjectProc(pid);
            }

            Console.ReadKey();
           //Application.Run(new MainForm());
        }
    }

}
