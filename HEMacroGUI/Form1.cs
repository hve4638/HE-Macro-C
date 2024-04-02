using System.Diagnostics;

namespace HEMacroGUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            WindowState = FormWindowState.Minimized;
            FormBorderStyle = FormBorderStyle.FixedToolWindow;
            ShowInTaskbar = false;
            Opacity = 0;
            Size = new Size(0, 0);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void ResetQueueMenuItem_Click(object sender, EventArgs e)
        {
            HEMacro.clearInputQueue();
        }

        private void DebugMenuItem_Click(object sender, EventArgs e)
        {
            var now = DateTime.Now;
            var filename = $"queuelog_{now:yyyyMdHHmmss}.txt";
            if (HEMacro.writeQueueLog(filename) != 0)
            {
                Process.Start("notepad.exe", filename);
            }
            else
            {
                MessageBox.Show($"couldn't open '{filename}'");
            }
        }

        private void ExitMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void ContextMenu_Opening(object sender, System.ComponentModel.CancelEventArgs e)
        {

        }
    }
}