namespace YZprj
{
    partial class Form1
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
            this.Onayla = new System.Windows.Forms.Button();
            this.fitness = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.textbox_population = new System.Windows.Forms.TextBox();
            this.generation = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.limit = new System.Windows.Forms.TextBox();
            this.mutate = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.durum = new System.Windows.Forms.Label();
            this.jenerasyon = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Onayla
            // 
            this.Onayla.Location = new System.Drawing.Point(671, 21);
            this.Onayla.Name = "Onayla";
            this.Onayla.Size = new System.Drawing.Size(75, 23);
            this.Onayla.TabIndex = 0;
            this.Onayla.Text = "Onayla";
            this.Onayla.UseVisualStyleBackColor = true;
            this.Onayla.Click += new System.EventHandler(this.Onayla_Click);
            // 
            // fitness
            // 
            this.fitness.AutoSize = true;
            this.fitness.Location = new System.Drawing.Point(671, 264);
            this.fitness.Name = "fitness";
            this.fitness.Size = new System.Drawing.Size(43, 13);
            this.fitness.TabIndex = 1;
            this.fitness.Text = "Fitness:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(671, 51);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(122, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Baslangıç popülasyonu :";
            // 
            // textbox_population
            // 
            this.textbox_population.Location = new System.Drawing.Point(674, 68);
            this.textbox_population.Name = "textbox_population";
            this.textbox_population.Size = new System.Drawing.Size(72, 20);
            this.textbox_population.TabIndex = 3;
            this.textbox_population.Text = "500";
            // 
            // generation
            // 
            this.generation.AutoSize = true;
            this.generation.Location = new System.Drawing.Point(671, 239);
            this.generation.Name = "generation";
            this.generation.Size = new System.Drawing.Size(62, 13);
            this.generation.TabIndex = 5;
            this.generation.Text = "Generation:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(674, 95);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(91, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Populasyon Limiti:";
            // 
            // limit
            // 
            this.limit.Location = new System.Drawing.Point(674, 112);
            this.limit.Name = "limit";
            this.limit.Size = new System.Drawing.Size(72, 20);
            this.limit.TabIndex = 7;
            this.limit.Text = "50";
            // 
            // mutate
            // 
            this.mutate.Location = new System.Drawing.Point(674, 152);
            this.mutate.Name = "mutate";
            this.mutate.Size = new System.Drawing.Size(72, 20);
            this.mutate.TabIndex = 9;
            this.mutate.Text = "33";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(674, 135);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Mutasyon Oranı (%)";
            // 
            // durum
            // 
            this.durum.AutoSize = true;
            this.durum.Location = new System.Drawing.Point(671, 291);
            this.durum.Name = "durum";
            this.durum.Size = new System.Drawing.Size(41, 13);
            this.durum.TabIndex = 14;
            this.durum.Text = "Durum:";
            // 
            // jenerasyon
            // 
            this.jenerasyon.Location = new System.Drawing.Point(674, 201);
            this.jenerasyon.Name = "jenerasyon";
            this.jenerasyon.Size = new System.Drawing.Size(72, 20);
            this.jenerasyon.TabIndex = 16;
            this.jenerasyon.Text = "5000";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(674, 184);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(117, 13);
            this.label4.TabIndex = 15;
            this.label4.Text = "Max Jenerasyon Sayısı:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(811, 351);
            this.Controls.Add(this.jenerasyon);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.durum);
            this.Controls.Add(this.mutate);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.limit);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.generation);
            this.Controls.Add(this.textbox_population);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.fitness);
            this.Controls.Add(this.Onayla);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Onayla;
        private System.Windows.Forms.Label fitness;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textbox_population;
        private System.Windows.Forms.Label generation;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox limit;
        private System.Windows.Forms.TextBox mutate;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label durum;
        private System.Windows.Forms.TextBox jenerasyon;
        private System.Windows.Forms.Label label4;
    }
}

