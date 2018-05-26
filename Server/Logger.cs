using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace Steamhook
{
    public enum LoggerMode
    {
        None,
        Console
    }

    public class Logger
    {
        public static Logger Server = new Logger("[SERVER] ");
        public static Logger Client = new Logger("[CLIENT] ");

        protected LoggerMode m_LoggerMode { get; set; }

        protected string m_Prefix { get; set; }

        public Logger(string prefix)
        {
            m_Prefix = prefix;
        }

        /// <summary>
        /// Allocate a console to display output
        /// </summary>
        public void StartConsole()
        {
            m_LoggerMode = LoggerMode.Console;
            ShowConsoleWindow();
            //AttachConsole(-1);
        }

        /// <summary>
        /// Print out a fatal message
        /// </summary>
        /// <param name="message"></param>
        /// <param name="e"></param>
        public void Error(string message, Exception e = null)
        {
            Spew($"[ERROR] {message}\n");
            if( e != null )
            {
                Spew($"{e.Message}\n");
            }
        }

        /// <summary>
        /// Print a debug message with a newline
        /// </summary>
        /// <param name="message"></param>
        public void DebugLine(string message)
        {
            Debug(message + "\n");
        }

        /// <summary>
        /// Print a debug message
        /// </summary>
        /// <param name="message"></param>
        public void Debug(string message)
        {
            Spew(message);
        }

        /// <summary>
        /// Print message to logger
        /// </summary>
        /// <param name="message"></param>
        private void Spew(string message)
        {
            if(m_LoggerMode == LoggerMode.Console)
            {
                Console.Write($"{m_Prefix} {message}");
            }
        }

        private static void ShowConsoleWindow()
        {
            var handle = GetConsoleWindow();

            if (handle == IntPtr.Zero)
            {
                AllocConsole();
            }
            else
            {
                ShowWindow(handle, SW_SHOW);
            }
        }

        private static void HideConsoleWindow()
        {
            var handle = GetConsoleWindow();

            ShowWindow(handle, SW_HIDE);
        }

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool AllocConsole();

        [DllImport("kernel32.dll")]
        static extern IntPtr GetConsoleWindow();

        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);

        const int SW_HIDE = 0;
        const int SW_SHOW = 5;
    }

}
