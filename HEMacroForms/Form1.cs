using System.Diagnostics;

namespace HEMacroForms
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
            if (HEMacro.writeInputQueue(filename))
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
    }
}