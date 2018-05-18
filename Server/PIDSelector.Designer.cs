namespace Server
{
    partial class PIDSelector
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.ProcListView = new System.Windows.Forms.ListView();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ProcListView
            // 
            this.ProcListView.Dock = System.Windows.Forms.DockStyle.Top;
            this.ProcListView.Location = new System.Drawing.Point(5, 5);
            this.ProcListView.Name = "ProcListView";
            this.ProcListView.Size = new System.Drawing.Size(674, 522);
            this.ProcListView.TabIndex = 0;
            this.ProcListView.UseCompatibleStateImageBehavior = false;
            this.ProcListView.DoubleClick += new System.EventHandler(this.ProcListView_DoubleClick);
            // 
            // button1
            // 
            this.button1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.button1.Location = new System.Drawing.Point(5, 533);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(674, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "Refresh";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // PIDSelector
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(684, 561);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.ProcListView);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "PIDSelector";
            this.Padding = new System.Windows.Forms.Padding(5);
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Select Process";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView ProcListView;
        private System.Windows.Forms.Button button1;
    }
}