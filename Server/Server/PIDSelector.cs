using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace Server
{
    public partial class PIDSelector : Form
    {
        public string SelectedPID { get; private set; }
        public object Task { get; private set; }

        public PIDSelector()
        {
            InitializeComponent();
            PopulateProcesses();
            SetWindowTheme(ProcListView.Handle, "Explorer", null);
            SelectedPID = null;
        }

        public void PopulateProcesses()
        {
            ProcListView.Items.Clear();

            ProcListView.View = View.Details;
            ProcListView.GridLines = true;

            ProcListView.Columns.Add("Process", -2);
            ProcListView.Columns.Add("Window", -2);

            ProcListView.SmallImageList = new ImageList();
            ProcListView.SmallImageList.ColorDepth = ColorDepth.Depth32Bit;
            ProcListView.SmallImageList.ImageSize = new Size(24, 24);

            ProcListView.Sorting = SortOrder.Ascending;
            ProcListView.FullRowSelect = true;

            var thread = new Thread(AddAllProcesses);
            thread.Start();
        }

        public void AddAllProcesses()
        {
            Process[] localAll = Process.GetProcesses();

            var curId = Process.GetCurrentProcess().Id.ToString();
            foreach ( var proc in localAll )
            {
                var procPid = proc.Id.ToString();
                var procWindow = proc.MainWindowTitle;
                var procName = proc.ProcessName;

                var ico = GetSmallWindowIcon(proc.MainWindowHandle);

                if( procWindow != "" && procPid != curId)
                {
                    AddProcess(ico, procPid, procName, procWindow);
                }
               
            }
        }

        public void AddProcess(Icon icon, string pid, string process, string windowTitle)
        {
            var item = new ListViewItem(new string[] { process, windowTitle });
            item.Tag = pid;

            ProcListView.BeginInvoke((Action)(() =>
            {
                ProcListView.Items.Add(item);
                ProcListView.SmallImageList.Images.Add(icon);
                if (icon != null)
                {
                    item.ImageIndex = ProcListView.SmallImageList.Images.Count - 1;
                }

                ProcListView.AutoResizeColumns(ColumnHeaderAutoResizeStyle.ColumnContent);
                //ProcListView.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
            }
            ));
        }

        [DllImport("uxtheme.dll", ExactSpelling = true, CharSet = CharSet.Unicode)]
        private static extern int SetWindowTheme(IntPtr hwnd, string pszSubAppName, string pszSubIdList);

        [DllImport("user32.dll")]
        static extern IntPtr SendMessage(IntPtr hWnd, uint Msg, IntPtr wParam, IntPtr lParam);

        [DllImport("user32.dll")]
        static extern IntPtr LoadIcon(IntPtr hInstance, IntPtr lpIconName);

        [DllImport("user32.dll", EntryPoint = "GetClassLong")]
        static extern uint GetClassLong32(IntPtr hWnd, int nIndex);

        [DllImport("user32.dll", EntryPoint = "GetClassLongPtr")]
        static extern IntPtr GetClassLong64(IntPtr hWnd, int nIndex);

        /// <summary>
        /// 64 bit version maybe loses significant 64-bit specific information
        /// </summary>
        static IntPtr GetClassLongPtr(IntPtr hWnd, int nIndex)
        {
            if (IntPtr.Size == 4)
                return new IntPtr((long)GetClassLong32(hWnd, nIndex));
            else
                return GetClassLong64(hWnd, nIndex);
        }
 
        public static Icon GetSmallWindowIcon(IntPtr hWnd)
        {
            uint WM_GETICON = 0x007f;
            IntPtr ICON_SMALL2 = new IntPtr(1);
            IntPtr IDI_APPLICATION = new IntPtr(0x7F00);
            int GCL_HICON = -14;
            try
            {
                IntPtr hIcon = default(IntPtr);

                hIcon = SendMessage(hWnd, WM_GETICON, ICON_SMALL2, IntPtr.Zero);

                if (hIcon == IntPtr.Zero)
                    hIcon = GetClassLongPtr(hWnd, GCL_HICON);

                if (hIcon == IntPtr.Zero)
                    hIcon = LoadIcon(IntPtr.Zero, (IntPtr)0x7F00/*IDI_APPLICATION*/);

                if (hIcon != IntPtr.Zero)
                    return Icon.FromHandle(hIcon);
                else
                    return null;
            }
            catch (Exception)
            {
                return null;
            }
        }

        private void ProcListView_DoubleClick(object sender, EventArgs e)
        {
            var selected = ProcListView.SelectedItems;
            if (selected.Count == 1)
            {
                SelectedPID = (string)selected[0].Tag;
                var selectedName = selected[0].SubItems[0].Text;
                var selectedText = selected[0].SubItems[1].Text;
                DialogResult dialogResult = MessageBox.Show($"Select '{selectedName} - {selectedText}'?", "Confirmation", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (dialogResult == DialogResult.Yes)
                {
                    this.Close();
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            PopulateProcesses();
        }
    }
}
