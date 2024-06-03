#pragma once
#include <string.h>
//#include "Controller.h"
//#include "ChangeStruct.h"
//#include "Draw.h"
//#include "Errors.h"
#include <string>

namespace Project3 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:

	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ ScaleButton;
	private: System::Windows::Forms::TextBox^ ScaleZTextBox;


	private: System::Windows::Forms::TextBox^ ScaleYTextBox;

	private: System::Windows::Forms::TextBox^ ScaleXTextBox;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ ShiftButton;
	private: System::Windows::Forms::TextBox^ ShiftZTextBox;


	private: System::Windows::Forms::TextBox^ ShiftYTextBox;

	private: System::Windows::Forms::TextBox^ ShiftXTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ RotateButton;
	private: System::Windows::Forms::TextBox^ RotationZTextBox;


	private: System::Windows::Forms::TextBox^ RotationYTextBox;

	private: System::Windows::Forms::TextBox^ RotationXTextBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->ScaleButton = (gcnew System::Windows::Forms::Button());
			this->ScaleZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ScaleYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ScaleXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->ShiftButton = (gcnew System::Windows::Forms::Button());
			this->ShiftZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ShiftYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ShiftXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->RotateButton = (gcnew System::Windows::Forms::Button());
			this->RotationZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RotationYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RotationXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Window;
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial Black", 16.125F, System::Drawing::FontStyle::Bold));
			this->groupBox1->ForeColor = System::Drawing::Color::YellowGreen;
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(499, 1210);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Меню";
			// 
			// groupBox5
			// 
			this->groupBox5->BackColor = System::Drawing::Color::PeachPuff;
			this->groupBox5->Controls->Add(this->ScaleButton);
			this->groupBox5->Controls->Add(this->ScaleZTextBox);
			this->groupBox5->Controls->Add(this->ScaleYTextBox);
			this->groupBox5->Controls->Add(this->ScaleXTextBox);
			this->groupBox5->Controls->Add(this->label7);
			this->groupBox5->Controls->Add(this->label8);
			this->groupBox5->Controls->Add(this->label9);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F));
			this->groupBox5->Location = System::Drawing::Point(6, 936);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(488, 265);
			this->groupBox5->TabIndex = 3;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Масштабирование";
			// 
			// ScaleButton
			// 
			this->ScaleButton->BackColor = System::Drawing::Color::YellowGreen;
			this->ScaleButton->ForeColor = System::Drawing::Color::Black;
			this->ScaleButton->Location = System::Drawing::Point(12, 183);
			this->ScaleButton->Name = L"ScaleButton";
			this->ScaleButton->Size = System::Drawing::Size(465, 67);
			this->ScaleButton->TabIndex = 1;
			this->ScaleButton->Text = L"Масштабировать";
			this->ScaleButton->UseVisualStyleBackColor = false;
			this->ScaleButton->Click += gcnew System::EventHandler(this, &MyForm::ScaleButton_Click);
			// 
			// ScaleZTextBox
			// 
			this->ScaleZTextBox->Location = System::Drawing::Point(326, 114);
			this->ScaleZTextBox->Name = L"ScaleZTextBox";
			this->ScaleZTextBox->Size = System::Drawing::Size(151, 50);
			this->ScaleZTextBox->TabIndex = 4;
			this->ScaleZTextBox->Text = L"1";
			// 
			// ScaleYTextBox
			// 
			this->ScaleYTextBox->Location = System::Drawing::Point(169, 114);
			this->ScaleYTextBox->Name = L"ScaleYTextBox";
			this->ScaleYTextBox->Size = System::Drawing::Size(151, 50);
			this->ScaleYTextBox->TabIndex = 2;
			this->ScaleYTextBox->Text = L"1";
			// 
			// ScaleXTextBox
			// 
			this->ScaleXTextBox->Location = System::Drawing::Point(12, 114);
			this->ScaleXTextBox->Name = L"ScaleXTextBox";
			this->ScaleXTextBox->Size = System::Drawing::Size(151, 50);
			this->ScaleXTextBox->TabIndex = 1;
			this->ScaleXTextBox->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(320, 65);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 36);
			this->label7->TabIndex = 3;
			this->label7->Text = L"kz:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(163, 65);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 36);
			this->label8->TabIndex = 2;
			this->label8->Text = L"ky:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(6, 65);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(54, 36);
			this->label9->TabIndex = 1;
			this->label9->Text = L"kx:";
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::PeachPuff;
			this->groupBox4->Controls->Add(this->ShiftButton);
			this->groupBox4->Controls->Add(this->ShiftZTextBox);
			this->groupBox4->Controls->Add(this->ShiftYTextBox);
			this->groupBox4->Controls->Add(this->ShiftXTextBox);
			this->groupBox4->Controls->Add(this->label4);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F));
			this->groupBox4->Location = System::Drawing::Point(5, 656);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(488, 274);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Перенос";
			// 
			// ShiftButton
			// 
			this->ShiftButton->BackColor = System::Drawing::Color::YellowGreen;
			this->ShiftButton->ForeColor = System::Drawing::Color::Black;
			this->ShiftButton->Location = System::Drawing::Point(12, 183);
			this->ShiftButton->Name = L"ShiftButton";
			this->ShiftButton->Size = System::Drawing::Size(465, 67);
			this->ShiftButton->TabIndex = 1;
			this->ShiftButton->Text = L"Перенести";
			this->ShiftButton->UseVisualStyleBackColor = false;
			this->ShiftButton->Click += gcnew System::EventHandler(this, &MyForm::ShiftButton_Click);
			// 
			// ShiftZTextBox
			// 
			this->ShiftZTextBox->Location = System::Drawing::Point(326, 114);
			this->ShiftZTextBox->Name = L"ShiftZTextBox";
			this->ShiftZTextBox->Size = System::Drawing::Size(151, 50);
			this->ShiftZTextBox->TabIndex = 4;
			this->ShiftZTextBox->Text = L"0";
			// 
			// ShiftYTextBox
			// 
			this->ShiftYTextBox->Location = System::Drawing::Point(169, 114);
			this->ShiftYTextBox->Name = L"ShiftYTextBox";
			this->ShiftYTextBox->Size = System::Drawing::Size(151, 50);
			this->ShiftYTextBox->TabIndex = 2;
			this->ShiftYTextBox->Text = L"0";
			// 
			// ShiftXTextBox
			// 
			this->ShiftXTextBox->Location = System::Drawing::Point(12, 114);
			this->ShiftXTextBox->Name = L"ShiftXTextBox";
			this->ShiftXTextBox->Size = System::Drawing::Size(151, 50);
			this->ShiftXTextBox->TabIndex = 1;
			this->ShiftXTextBox->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(320, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 36);
			this->label4->TabIndex = 3;
			this->label4->Text = L"dz:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(163, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 36);
			this->label5->TabIndex = 2;
			this->label5->Text = L"dy:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(6, 65);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 36);
			this->label6->TabIndex = 1;
			this->label6->Text = L"dx:";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::PeachPuff;
			this->groupBox3->Controls->Add(this->RotateButton);
			this->groupBox3->Controls->Add(this->RotationZTextBox);
			this->groupBox3->Controls->Add(this->RotationYTextBox);
			this->groupBox3->Controls->Add(this->RotationXTextBox);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F));
			this->groupBox3->Location = System::Drawing::Point(5, 376);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(488, 274);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Поворот (градусы)";
			// 
			// RotateButton
			// 
			this->RotateButton->BackColor = System::Drawing::Color::YellowGreen;
			this->RotateButton->ForeColor = System::Drawing::Color::Black;
			this->RotateButton->Location = System::Drawing::Point(12, 183);
			this->RotateButton->Name = L"RotateButton";
			this->RotateButton->Size = System::Drawing::Size(465, 67);
			this->RotateButton->TabIndex = 1;
			this->RotateButton->Text = L"Повернуть";
			this->RotateButton->UseVisualStyleBackColor = false;
			this->RotateButton->Click += gcnew System::EventHandler(this, &MyForm::RotateButton_Click);
			// 
			// RotationZTextBox
			// 
			this->RotationZTextBox->Location = System::Drawing::Point(326, 114);
			this->RotationZTextBox->Name = L"RotationZTextBox";
			this->RotationZTextBox->Size = System::Drawing::Size(151, 50);
			this->RotationZTextBox->TabIndex = 4;
			this->RotationZTextBox->Text = L"0";
			// 
			// RotationYTextBox
			// 
			this->RotationYTextBox->Location = System::Drawing::Point(169, 114);
			this->RotationYTextBox->Name = L"RotationYTextBox";
			this->RotationYTextBox->Size = System::Drawing::Size(151, 50);
			this->RotationYTextBox->TabIndex = 2;
			this->RotationYTextBox->Text = L"0";
			// 
			// RotationXTextBox
			// 
			this->RotationXTextBox->Location = System::Drawing::Point(12, 114);
			this->RotationXTextBox->Name = L"RotationXTextBox";
			this->RotationXTextBox->Size = System::Drawing::Size(151, 50);
			this->RotationXTextBox->TabIndex = 1;
			this->RotationXTextBox->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(320, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 36);
			this->label3->TabIndex = 3;
			this->label3->Text = L"OZ:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(163, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 36);
			this->label2->TabIndex = 2;
			this->label2->Text = L"OY:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(6, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 36);
			this->label1->TabIndex = 1;
			this->label1->Text = L"OX:";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::PeachPuff;
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F));
			this->groupBox2->Location = System::Drawing::Point(6, 67);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(488, 303);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Модель";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(11, 220);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(464, 66);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Выбрать файл";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(11, 181);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(180, 36);
			this->label11->TabIndex = 2;
			this->label11->Text = L"Сохранить:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(11, 73);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(169, 36);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Загрузить:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(6, 112);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(464, 66);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Выбрать файл";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(2170, 1225);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Лабораторная работа №3";
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->groupBox1->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		int offset_x = (this->ClientSize.Width - groupBox1->Width) / 2 + groupBox1->Width;
		int offset_y = this->ClientSize.Height / 2;
		/*change_t ch{};
		draw_t ch_draw{};
		ch.mode = DRAWING;
		ch_draw.offset_x = offset_x;
		ch_draw.offset_y = offset_y;
		ch_draw.e = e;
		error_t rc = controller(&ch, &ch_draw);*/
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: Void start_position()
	{
		RotationXTextBox->Text = "0";
		RotationYTextBox->Text = "0";
		RotationZTextBox->Text = "0";
		ShiftXTextBox->Text = "0";
		ShiftYTextBox->Text = "0";
		ShiftZTextBox->Text = "0";
		ScaleXTextBox->Text = "1";
		ScaleYTextBox->Text = "1";
		ScaleZTextBox->Text = "1";
	}
	/*private: Void error_message(error_t rc)
	{
		if (rc != ERR_OK)
		{
			System::String^ message = error_controller(rc);
			MessageBox::Show(message);
		}
	}*/
	private: System::Void RotateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		/*error_t rc = ERR_OK;
		change_t ch{};
		ch.mode = ROTATION;
		if (!int::TryParse(RotationXTextBox->Text, ch.rotation.X))
			rc = ERR_ANGLE;
		if (!int::TryParse(RotationYTextBox->Text, ch.rotation.Y)) 
			rc = ERR_ANGLE;
		if (!int::TryParse(RotationZTextBox->Text, ch.rotation.Z)) 
			rc = ERR_ANGLE;
		if (rc == ERR_OK)
			rc = controller(&ch, NULL);
		error_message(rc);*/
		this->Invalidate();
	}
	private: System::Void ShiftButton_Click(System::Object^ sender, System::EventArgs^ e) {
		/*error_t rc = ERR_OK;
		change_t ch{};
		ch.mode = SHIFTING;
		if (!int::TryParse(ShiftXTextBox->Text, ch.shifting.X))
			rc = ERR_D;
		if (!int::TryParse(ShiftYTextBox->Text, ch.shifting.Y)) 
			rc = ERR_D;
		if (!int::TryParse(ShiftZTextBox->Text, ch.shifting.Z))
			rc = ERR_D;
		if (rc == ERR_OK)
			rc = controller(&ch, NULL);
		error_message(rc);*/
		this->Invalidate();
	}
	private: System::Void ScaleButton_Click(System::Object^ sender, System::EventArgs^ e) {
		/*error_t rc = ERR_OK;
		change ch{};
		ch.mode = SCALING;
		if (!double::TryParse(ScaleXTextBox->Text, ch.scaling.X))
			rc = ERR_K;
		if (!double::TryParse(ScaleYTextBox->Text, ch.scaling.Y)) 
			rc = ERR_K;
		if (!double::TryParse(ScaleZTextBox->Text, ch.scaling.Z)) 
			rc = ERR_K;
		if (rc == ERR_OK)
			rc = controller(&ch, NULL);
		error_message(rc);*/
		this->Invalidate();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->openFileDialog1->ShowDialog();
		String^ file_path = this->openFileDialog1->FileName;
		file_path = file_path->Replace("\\", "/");
		char* c_path = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(file_path);

		/*change_t ch{};
		ch.mode = LOADING;
		ch.loading.path = c_path;
		error_t rc = controller(&ch, NULL);
		error_message(rc);
		if (rc == ERR_OK)
		{
			start_position();
			this->Invalidate();
		}
		if (c_path)
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)c_path);*/
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->saveFileDialog1->ShowDialog();
		String^ file_path = this->saveFileDialog1->FileName;
		file_path = file_path->Replace("\\", "/");
		char* c_path = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(file_path);

		/*change_t ch{};
		ch.mode = SAVING;
		ch.loading.path = c_path;
		error_t rc = controller(&ch, NULL);
		error_message(rc);
		if (rc == ERR_OK)
		{
			start_position();
			this->Invalidate();
		}
		if (c_path)
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)c_path);*/
	}
};
}
