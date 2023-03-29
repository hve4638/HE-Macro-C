namespace HEMacroForms
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            Notification = new NotifyIcon(components);
            ContextMenu = new ContextMenuStrip(components);
            ResetQueueMenuItem = new ToolStripMenuItem();
            DebugMenuItem = new ToolStripMenuItem();
            ExitMenuItem = new ToolStripMenuItem();
            ContextMenu.SuspendLayout();
            SuspendLayout();
            // 
            // Notification
            // 
            Notification.BalloonTipIcon = ToolTipIcon.Info;
            Notification.ContextMenuStrip = ContextMenu;
            Notification.Icon = (Icon)resources.GetObject("Notification.Icon");
            Notification.Text = "HEMacro";
            Notification.Visible = true;
            // 
            // ContextMenu
            // 
            ContextMenu.ImageScalingSize = new Size(36, 36);
            ContextMenu.Items.AddRange(new ToolStripItem[] { ResetQueueMenuItem, DebugMenuItem, ExitMenuItem });
            ContextMenu.Name = "contextMenuStrip1";
            ContextMenu.Size = new Size(138, 70);
            // 
            // ResetQueueMenuItem
            // 
            ResetQueueMenuItem.Name = "ResetQueueMenuItem";
            ResetQueueMenuItem.Size = new Size(137, 22);
            ResetQueueMenuItem.Text = "ResetQueue";
            ResetQueueMenuItem.Click += ResetQueueMenuItem_Click;
            // 
            // DebugMenuItem
            // 
            DebugMenuItem.Name = "DebugMenuItem";
            DebugMenuItem.Size = new Size(137, 22);
            DebugMenuItem.Text = "Debug";
            DebugMenuItem.Click += DebugMenuItem_Click;
            // 
            // ExitMenuItem
            // 
            ExitMenuItem.Name = "ExitMenuItem";
            ExitMenuItem.Size = new Size(137, 22);
            ExitMenuItem.Text = "Exit";
            ExitMenuItem.Click += ExitMenuItem_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(373, 182);
            Margin = new Padding(1);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ContextMenu.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private NotifyIcon Notification;
        private ContextMenuStrip ContextMenu;
        private ToolStripMenuItem ResetQueueMenuItem;
        private ToolStripMenuItem DebugMenuItem;
        private ToolStripMenuItem ExitMenuItem;
    }
}