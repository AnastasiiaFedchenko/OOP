#pragma once
#include <iostream>
//#include <sstream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "objects/model/point.h"
#include "objects/canvas.h"
#include "building_classes/loader_solution.h"
#include "drawing_classes/win_forms_drawer.h"
//#include "Controller.h"
//#include "ChangeStruct.h"
//#include "Draw.h"
//#include "Errors.h"
#include <string>
#include "drawing_classes/abstract_factory.h"
#include "drawing_classes/win_forms_factory.h"
#include "drawing_classes/drawer_solution.h"
#include "visitor/draw_all.h"
#include "managers/draw_manager.h"
#include "facade.h"
#include "commands/base_draw_command.h"
#include "commands/base_scene_command.h"
#include "commands/base_load_command.h"

namespace Project3 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::shared_ptr<Facade>facade;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			bitmap = (gcnew System::Drawing::Bitmap(this->screen->Width, this->screen->Height));
			graphics = Graphics::FromImage(bitmap);
			pen = gcnew Pen(Color::Fuchsia, 3.f);
			brush = gcnew SolidBrush(Color::White);
			canv.g = graphics;
			canv.pen = pen;
			canv.brush = brush;
			canv.backcolor = Color::White;
			canv.width = screen->Width;
			canv.height = screen->Height;
			//canv = canvas_t( graphics, pen, Color::White, ,  );
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
	//private: System::Windows::Forms::Button^ button2;
	//private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::PictureBox^ screen;



	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;



	private: System::Drawing::Bitmap^ bitmap;
	private: static System::Drawing::Graphics^ graphics;
	private: System::Drawing::Pen^ pen;
	private: System::Drawing::Brush^ brush;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Button^ RotateButton;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: canvas_t canv;
	//private: pin_ptr<canvas_t> ptr;


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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->screen = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->screen))->BeginInit();
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
			this->groupBox5->Location = System::Drawing::Point(6, 1008);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(488, 193);
			this->groupBox5->TabIndex = 3;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Масштабирование";
			// 
			// ScaleButton
			// 
			this->ScaleButton->BackColor = System::Drawing::Color::YellowGreen;
			this->ScaleButton->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ScaleButton->ForeColor = System::Drawing::Color::Black;
			this->ScaleButton->Location = System::Drawing::Point(12, 135);
			this->ScaleButton->Name = L"ScaleButton";
			this->ScaleButton->Size = System::Drawing::Size(465, 51);
			this->ScaleButton->TabIndex = 1;
			this->ScaleButton->Text = L"Масштабировать";
			this->ScaleButton->UseVisualStyleBackColor = false;
			this->ScaleButton->Click += gcnew System::EventHandler(this, &MyForm::ScaleButton_Click);
			// 
			// ScaleZTextBox
			// 
			this->ScaleZTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ScaleZTextBox->Location = System::Drawing::Point(326, 85);
			this->ScaleZTextBox->Name = L"ScaleZTextBox";
			this->ScaleZTextBox->Size = System::Drawing::Size(151, 44);
			this->ScaleZTextBox->TabIndex = 4;
			this->ScaleZTextBox->Text = L"1";
			// 
			// ScaleYTextBox
			// 
			this->ScaleYTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ScaleYTextBox->Location = System::Drawing::Point(169, 85);
			this->ScaleYTextBox->Name = L"ScaleYTextBox";
			this->ScaleYTextBox->Size = System::Drawing::Size(151, 44);
			this->ScaleYTextBox->TabIndex = 2;
			this->ScaleYTextBox->Text = L"1";
			// 
			// ScaleXTextBox
			// 
			this->ScaleXTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ScaleXTextBox->Location = System::Drawing::Point(12, 85);
			this->ScaleXTextBox->Name = L"ScaleXTextBox";
			this->ScaleXTextBox->Size = System::Drawing::Size(151, 44);
			this->ScaleXTextBox->TabIndex = 1;
			this->ScaleXTextBox->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(319, 46);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 36);
			this->label7->TabIndex = 3;
			this->label7->Text = L"kz:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(162, 46);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 36);
			this->label8->TabIndex = 2;
			this->label8->Text = L"ky:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(5, 46);
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
			this->groupBox4->Location = System::Drawing::Point(6, 811);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(488, 191);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Перенос";
			// 
			// ShiftButton
			// 
			this->ShiftButton->BackColor = System::Drawing::Color::YellowGreen;
			this->ShiftButton->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ShiftButton->ForeColor = System::Drawing::Color::Black;
			this->ShiftButton->Location = System::Drawing::Point(12, 135);
			this->ShiftButton->Name = L"ShiftButton";
			this->ShiftButton->Size = System::Drawing::Size(466, 47);
			this->ShiftButton->TabIndex = 1;
			this->ShiftButton->Text = L"Перенести";
			this->ShiftButton->UseVisualStyleBackColor = false;
			this->ShiftButton->Click += gcnew System::EventHandler(this, &MyForm::ShiftButton_Click);
			// 
			// ShiftZTextBox
			// 
			this->ShiftZTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ShiftZTextBox->Location = System::Drawing::Point(327, 85);
			this->ShiftZTextBox->Name = L"ShiftZTextBox";
			this->ShiftZTextBox->Size = System::Drawing::Size(151, 44);
			this->ShiftZTextBox->TabIndex = 4;
			this->ShiftZTextBox->Text = L"0";
			// 
			// ShiftYTextBox
			// 
			this->ShiftYTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ShiftYTextBox->Location = System::Drawing::Point(170, 85);
			this->ShiftYTextBox->Name = L"ShiftYTextBox";
			this->ShiftYTextBox->Size = System::Drawing::Size(151, 44);
			this->ShiftYTextBox->TabIndex = 2;
			this->ShiftYTextBox->Text = L"0";
			// 
			// ShiftXTextBox
			// 
			this->ShiftXTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ShiftXTextBox->Location = System::Drawing::Point(13, 85);
			this->ShiftXTextBox->Name = L"ShiftXTextBox";
			this->ShiftXTextBox->Size = System::Drawing::Size(151, 44);
			this->ShiftXTextBox->TabIndex = 1;
			this->ShiftXTextBox->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(321, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 36);
			this->label4->TabIndex = 3;
			this->label4->Text = L"dz:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(164, 46);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 36);
			this->label5->TabIndex = 2;
			this->label5->Text = L"dy:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(7, 46);
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
			this->groupBox3->Location = System::Drawing::Point(5, 615);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(488, 190);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Поворот (градусы)";
			// 
			// RotateButton
			// 
			this->RotateButton->BackColor = System::Drawing::Color::YellowGreen;
			this->RotateButton->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RotateButton->ForeColor = System::Drawing::Color::Black;
			this->RotateButton->Location = System::Drawing::Point(13, 135);
			this->RotateButton->Name = L"RotateButton";
			this->RotateButton->Size = System::Drawing::Size(464, 47);
			this->RotateButton->TabIndex = 1;
			this->RotateButton->Text = L"Повернуть";
			this->RotateButton->UseVisualStyleBackColor = false;
			this->RotateButton->Click += gcnew System::EventHandler(this, &MyForm::RotateButton_Click);
			// 
			// RotationZTextBox
			// 
			this->RotationZTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RotationZTextBox->Location = System::Drawing::Point(326, 85);
			this->RotationZTextBox->Name = L"RotationZTextBox";
			this->RotationZTextBox->Size = System::Drawing::Size(151, 44);
			this->RotationZTextBox->TabIndex = 4;
			this->RotationZTextBox->Text = L"0";
			// 
			// RotationYTextBox
			// 
			this->RotationYTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RotationYTextBox->Location = System::Drawing::Point(169, 85);
			this->RotationYTextBox->Name = L"RotationYTextBox";
			this->RotationYTextBox->Size = System::Drawing::Size(151, 44);
			this->RotationYTextBox->TabIndex = 2;
			this->RotationYTextBox->Text = L"0";
			// 
			// RotationXTextBox
			// 
			this->RotationXTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RotationXTextBox->Location = System::Drawing::Point(12, 85);
			this->RotationXTextBox->Name = L"RotationXTextBox";
			this->RotationXTextBox->Size = System::Drawing::Size(151, 44);
			this->RotationXTextBox->TabIndex = 1;
			this->RotationXTextBox->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(321, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 36);
			this->label3->TabIndex = 3;
			this->label3->Text = L"OZ:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(164, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 36);
			this->label2->TabIndex = 2;
			this->label2->Text = L"OY:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(7, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 36);
			this->label1->TabIndex = 1;
			this->label1->Text = L"OX:";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::PeachPuff;
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->checkedListBox1);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F));
			this->groupBox2->Location = System::Drawing::Point(6, 67);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(488, 542);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Модель";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::YellowGreen;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(14, 489);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(464, 47);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Отчистить всё";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::YellowGreen;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(14, 439);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(464, 47);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(13, 147);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(463, 286);
			this->checkedListBox1->TabIndex = 2;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(6, 46);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(169, 36);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Загрузить:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(6, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(464, 56);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Выбрать файл";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// screen
			// 
			this->screen->Location = System::Drawing::Point(528, 12);
			this->screen->Name = L"screen";
			this->screen->Size = System::Drawing::Size(1630, 1210);
			this->screen->TabIndex = 1;
			this->screen->TabStop = false;
			this->screen->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::screen_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(2170, 1225);
			this->Controls->Add(this->screen);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->screen))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		pin_ptr<canvas_t> ptr = &canv;

		std::shared_ptr<Camera> c = std::make_shared<Camera>(std::make_shared<CameraData>(My_Point(0, 0, 0), My_Point(0, 0, 0)));
		std::shared_ptr<AbstractFactory> f = std::make_shared<WinFormsFactory>(WinFormsFactory(ptr));
		std::shared_ptr<DrawAll> v = std::make_shared<DrawAll>(f, c);

		facade = std::make_shared<Facade>(Facade(v));
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
	private: System::Void RotateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int ang_x, ang_y, ang_z;
		if (!int::TryParse(RotationXTextBox->Text, ang_x))
			throw std::exception();
		if (!int::TryParse(RotationYTextBox->Text, ang_y)) 
			throw std::exception();
		if (!int::TryParse(RotationZTextBox->Text, ang_z)) 
			throw std::exception();
		std::vector<size_t> models;
		std::vector<size_t> cameras;
		auto checked = checkedListBox1->CheckedItems;
		
		for (int i = 0; i < checked->Count; i++)
		{
			String^ s = checked[i]->ToString();
			string str = msclr::interop::marshal_as<std::string>(s);
			size_t result = (size_t)atoi(str.c_str());
			models.push_back(result);
		}
		RotateCommand cmd(models, cameras, ang_x, ang_y, ang_z);
		facade->execute(cmd);
		screen->Invalidate();
	}
	private: System::Void ShiftButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int dx, dy, dz;
		if (!int::TryParse(ShiftXTextBox->Text, dx))
			throw std::exception();
		if (!int::TryParse(ShiftYTextBox->Text, dy)) 
			throw std::exception();
		if (!int::TryParse(ShiftZTextBox->Text, dz))
			throw std::exception();
		std::vector<size_t> models;
		std::vector<size_t> cameras;
		auto checked = checkedListBox1->CheckedItems;

		for (int i = 0; i < checked->Count; i++)
		{
			String^ s = checked[i]->ToString();
			string str = msclr::interop::marshal_as<std::string>(s);
			size_t result = (size_t)atoi(str.c_str());
			models.push_back(result);
		}
		ShiftCommand cmd(models, cameras, dx, dy, dz);
		facade->execute(cmd);
		screen->Invalidate();
	}
	private: System::Void ScaleButton_Click(System::Object^ sender, System::EventArgs^ e) {
		double kx, ky, kz;
		if (!double::TryParse(ScaleXTextBox->Text, kx))
			throw std::exception();
		if (!double::TryParse(ScaleYTextBox->Text, ky)) 
			throw std::exception();
		if (!double::TryParse(ScaleZTextBox->Text, kz)) 
			throw std::exception();;
		std::vector<size_t> models;
		std::vector<size_t> cameras;
		auto checked = checkedListBox1->CheckedItems;

		for (int i = 0; i < checked->Count; i++)
		{
			String^ s = checked[i]->ToString();
			string str = msclr::interop::marshal_as<std::string>(s);
			size_t result = (size_t)atoi(str.c_str());
			models.push_back(result);
		}
		ScaleCommand cmd(models, cameras, kx, ky, kz);
		facade->execute(cmd);
		screen->Invalidate();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->openFileDialog1->ShowDialog();
		String^ file_path = this->openFileDialog1->FileName;
		file_path = file_path->Replace("\\", "/");
		string c_path = msclr::interop::marshal_as<std::string>(file_path);

		std::shared_ptr<BaseObject> obj;
		FileLoadModelCommand cmd(obj, c_path);
		facade->execute(cmd);

		std::shared_ptr<size_t> id = std::make_shared<size_t>(0);
		AddObjectCommand cmd2(obj, id);
		facade->execute(cmd2);

		size_t id_number = *id;
		checkedListBox1->BeginUpdate();
		checkedListBox1->Items->Add(id_number, true);
		checkedListBox1->EndUpdate();

		screen->Invalidate();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->saveFileDialog1->ShowDialog();
		String^ file_path = this->saveFileDialog1->FileName;
		file_path = file_path->Replace("\\", "/");
		char* c_path = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(file_path);

		this->Invalidate();
		if (c_path)
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)c_path);
	}
	private: System::Void screen_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		graphics->FillRectangle(canv.brush, 0, 0, canv.width, canv.height);
		Graphics^ g = e->Graphics;
		std::shared_ptr<Scene> scene = std::make_shared<Scene>(Scene());

		GetSceneCommand cmd(scene);
		facade->execute(cmd);

		if (scene != nullptr)
		{ 
			DrawSceneCommand cmd2(scene);
			facade->execute(cmd2);
		}
		g->DrawImage(bitmap, 0, 0);
	}
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) 
	{
		//std::vector<size_t> models;
		//std::vector<size_t> cameras;
		auto checked = checkedListBox1->CheckedItems;

		for (int i = 0; i < checked->Count; i++)
		{
			String^ s = checked[i]->ToString();
			string str = msclr::interop::marshal_as<std::string>(s);
			size_t result = (size_t)atoi(str.c_str());
	
			DeleteObjectCommand cmd(result);
			facade->execute(cmd);
			checkedListBox1->Items->Remove(checked[i]);
		}
		screen->Invalidate();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		auto items = checkedListBox1->Items;

		size_t original_amount = items->Count;
		for (int i = 0; i < original_amount; i++)
		{
			String^ s = items[0]->ToString();
			string str = msclr::interop::marshal_as<std::string>(s);
			size_t result = (size_t)atoi(str.c_str());

			DeleteObjectCommand cmd(result);
			facade->execute(cmd);
			checkedListBox1->Items->Remove(items[0]);
		}
		screen->Invalidate();
	}
};
}
