#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ RotationGroupBox;
	private: System::Windows::Forms::Button^ RotationButton;
	private: System::Windows::Forms::Label^ OZLabel;
	private: System::Windows::Forms::Label^ OYLabel;
	private: System::Windows::Forms::TextBox^ OZTextBox;
	private: System::Windows::Forms::TextBox^ OYTextBox;
	private: System::Windows::Forms::TextBox^ OXTextBox;
	private: System::Windows::Forms::Label^ OXLabel;
	private: System::Windows::Forms::GroupBox^ ShiftGroupBox;
	private: System::Windows::Forms::Button^ ShiftButton;
	private: System::Windows::Forms::Label^ DzLabel;
	private: System::Windows::Forms::Label^ DyLabel;
	private: System::Windows::Forms::TextBox^ DzTextBox;
	private: System::Windows::Forms::TextBox^ DyTextBox;
	private: System::Windows::Forms::TextBox^ DxTextBox;
	private: System::Windows::Forms::Label^ DxLabel;
	private: System::Windows::Forms::GroupBox^ ScalingGroupBox;
	private: System::Windows::Forms::Button^ ScalingButton;
	private: System::Windows::Forms::Label^ KzLabel;
	private: System::Windows::Forms::Label^ KyLabel;
	private: System::Windows::Forms::TextBox^ KzTextBox;
	private: System::Windows::Forms::TextBox^ KyTextBox;
	private: System::Windows::Forms::TextBox^ KxTextBox;
	private: System::Windows::Forms::Label^ KxLabel;
	private: System::Windows::Forms::Button^ ZeroButton;
	private: System::Windows::Forms::ComboBox^ ModelComboBox;
	private: System::Windows::Forms::GroupBox^ ModelGroupBox;
	private: System::Windows::Forms::GroupBox^ MenuGroupBox;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->RotationGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->RotationButton = (gcnew System::Windows::Forms::Button());
			this->OZLabel = (gcnew System::Windows::Forms::Label());
			this->OYLabel = (gcnew System::Windows::Forms::Label());
			this->OZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OXLabel = (gcnew System::Windows::Forms::Label());
			this->ShiftGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->ShiftButton = (gcnew System::Windows::Forms::Button());
			this->DzLabel = (gcnew System::Windows::Forms::Label());
			this->DyLabel = (gcnew System::Windows::Forms::Label());
			this->DzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DxLabel = (gcnew System::Windows::Forms::Label());
			this->ScalingGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->ScalingButton = (gcnew System::Windows::Forms::Button());
			this->KzLabel = (gcnew System::Windows::Forms::Label());
			this->KyLabel = (gcnew System::Windows::Forms::Label());
			this->KzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->KyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->KxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->KxLabel = (gcnew System::Windows::Forms::Label());
			this->ZeroButton = (gcnew System::Windows::Forms::Button());
			this->ModelComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ModelGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->MenuGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->RotationGroupBox->SuspendLayout();
			this->ShiftGroupBox->SuspendLayout();
			this->ScalingGroupBox->SuspendLayout();
			this->ModelGroupBox->SuspendLayout();
			this->MenuGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// RotationGroupBox
			// 
			this->RotationGroupBox->BackColor = System::Drawing::Color::PeachPuff;
			this->RotationGroupBox->Controls->Add(this->RotationButton);
			this->RotationGroupBox->Controls->Add(this->OZLabel);
			this->RotationGroupBox->Controls->Add(this->OYLabel);
			this->RotationGroupBox->Controls->Add(this->OZTextBox);
			this->RotationGroupBox->Controls->Add(this->OYTextBox);
			this->RotationGroupBox->Controls->Add(this->OXTextBox);
			this->RotationGroupBox->Controls->Add(this->OXLabel);
			this->RotationGroupBox->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RotationGroupBox->ForeColor = System::Drawing::Color::Black;
			this->RotationGroupBox->Location = System::Drawing::Point(12, 249);
			this->RotationGroupBox->Name = L"RotationGroupBox";
			this->RotationGroupBox->Size = System::Drawing::Size(472, 269);
			this->RotationGroupBox->TabIndex = 0;
			this->RotationGroupBox->TabStop = false;
			this->RotationGroupBox->Text = L"Поворот (градусы)";
			this->RotationGroupBox->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// RotationButton
			// 
			this->RotationButton->BackColor = System::Drawing::Color::YellowGreen;
			this->RotationButton->ForeColor = System::Drawing::Color::Black;
			this->RotationButton->Location = System::Drawing::Point(6, 173);
			this->RotationButton->Name = L"RotationButton";
			this->RotationButton->Size = System::Drawing::Size(460, 71);
			this->RotationButton->TabIndex = 1;
			this->RotationButton->Text = L"Повернуть";
			this->RotationButton->UseVisualStyleBackColor = false;
			// 
			// OZLabel
			// 
			this->OZLabel->AutoSize = true;
			this->OZLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OZLabel->Location = System::Drawing::Point(324, 78);
			this->OZLabel->Name = L"OZLabel";
			this->OZLabel->Size = System::Drawing::Size(69, 36);
			this->OZLabel->TabIndex = 5;
			this->OZLabel->Text = L"OZ:";
			// 
			// OYLabel
			// 
			this->OYLabel->AutoSize = true;
			this->OYLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OYLabel->Location = System::Drawing::Point(161, 78);
			this->OYLabel->Name = L"OYLabel";
			this->OYLabel->Size = System::Drawing::Size(68, 36);
			this->OYLabel->TabIndex = 4;
			this->OYLabel->Text = L"OY:";
			// 
			// OZTextBox
			// 
			this->OZTextBox->Location = System::Drawing::Point(330, 117);
			this->OZTextBox->Name = L"OZTextBox";
			this->OZTextBox->Size = System::Drawing::Size(136, 50);
			this->OZTextBox->TabIndex = 3;
			this->OZTextBox->Text = L"0";
			// 
			// OYTextBox
			// 
			this->OYTextBox->Location = System::Drawing::Point(167, 117);
			this->OYTextBox->Name = L"OYTextBox";
			this->OYTextBox->Size = System::Drawing::Size(136, 50);
			this->OYTextBox->TabIndex = 2;
			this->OYTextBox->Text = L"0";
			// 
			// OXTextBox
			// 
			this->OXTextBox->Location = System::Drawing::Point(6, 117);
			this->OXTextBox->Name = L"OXTextBox";
			this->OXTextBox->Size = System::Drawing::Size(136, 50);
			this->OXTextBox->TabIndex = 1;
			this->OXTextBox->Text = L"0";
			// 
			// OXLabel
			// 
			this->OXLabel->AutoSize = true;
			this->OXLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OXLabel->Location = System::Drawing::Point(6, 78);
			this->OXLabel->Name = L"OXLabel";
			this->OXLabel->Size = System::Drawing::Size(70, 36);
			this->OXLabel->TabIndex = 1;
			this->OXLabel->Text = L"OX:";
			// 
			// ShiftGroupBox
			// 
			this->ShiftGroupBox->BackColor = System::Drawing::Color::PeachPuff;
			this->ShiftGroupBox->Controls->Add(this->ShiftButton);
			this->ShiftGroupBox->Controls->Add(this->DzLabel);
			this->ShiftGroupBox->Controls->Add(this->DyLabel);
			this->ShiftGroupBox->Controls->Add(this->DzTextBox);
			this->ShiftGroupBox->Controls->Add(this->DyTextBox);
			this->ShiftGroupBox->Controls->Add(this->DxTextBox);
			this->ShiftGroupBox->Controls->Add(this->DxLabel);
			this->ShiftGroupBox->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ShiftGroupBox->ForeColor = System::Drawing::Color::Black;
			this->ShiftGroupBox->Location = System::Drawing::Point(12, 524);
			this->ShiftGroupBox->Name = L"ShiftGroupBox";
			this->ShiftGroupBox->Size = System::Drawing::Size(472, 269);
			this->ShiftGroupBox->TabIndex = 1;
			this->ShiftGroupBox->TabStop = false;
			this->ShiftGroupBox->Text = L"Перенос";
			// 
			// ShiftButton
			// 
			this->ShiftButton->BackColor = System::Drawing::Color::YellowGreen;
			this->ShiftButton->Location = System::Drawing::Point(6, 173);
			this->ShiftButton->Name = L"ShiftButton";
			this->ShiftButton->Size = System::Drawing::Size(460, 71);
			this->ShiftButton->TabIndex = 1;
			this->ShiftButton->Text = L"Перенести";
			this->ShiftButton->UseVisualStyleBackColor = false;
			// 
			// DzLabel
			// 
			this->DzLabel->AutoSize = true;
			this->DzLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DzLabel->Location = System::Drawing::Point(324, 78);
			this->DzLabel->Name = L"DzLabel";
			this->DzLabel->Size = System::Drawing::Size(56, 36);
			this->DzLabel->TabIndex = 5;
			this->DzLabel->Text = L"dz:";
			// 
			// DyLabel
			// 
			this->DyLabel->AutoSize = true;
			this->DyLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DyLabel->Location = System::Drawing::Point(161, 78);
			this->DyLabel->Name = L"DyLabel";
			this->DyLabel->Size = System::Drawing::Size(56, 36);
			this->DyLabel->TabIndex = 4;
			this->DyLabel->Text = L"dy:";
			// 
			// DzTextBox
			// 
			this->DzTextBox->Location = System::Drawing::Point(330, 117);
			this->DzTextBox->Name = L"DzTextBox";
			this->DzTextBox->Size = System::Drawing::Size(136, 50);
			this->DzTextBox->TabIndex = 3;
			this->DzTextBox->Text = L"0";
			// 
			// DyTextBox
			// 
			this->DyTextBox->Location = System::Drawing::Point(167, 117);
			this->DyTextBox->Name = L"DyTextBox";
			this->DyTextBox->Size = System::Drawing::Size(136, 50);
			this->DyTextBox->TabIndex = 2;
			this->DyTextBox->Text = L"0";
			// 
			// DxTextBox
			// 
			this->DxTextBox->Location = System::Drawing::Point(6, 117);
			this->DxTextBox->Name = L"DxTextBox";
			this->DxTextBox->Size = System::Drawing::Size(136, 50);
			this->DxTextBox->TabIndex = 1;
			this->DxTextBox->Text = L"0";
			// 
			// DxLabel
			// 
			this->DxLabel->AutoSize = true;
			this->DxLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DxLabel->Location = System::Drawing::Point(6, 78);
			this->DxLabel->Name = L"DxLabel";
			this->DxLabel->Size = System::Drawing::Size(55, 36);
			this->DxLabel->TabIndex = 1;
			this->DxLabel->Text = L"dx:";
			// 
			// ScalingGroupBox
			// 
			this->ScalingGroupBox->BackColor = System::Drawing::Color::PeachPuff;
			this->ScalingGroupBox->Controls->Add(this->ScalingButton);
			this->ScalingGroupBox->Controls->Add(this->KzLabel);
			this->ScalingGroupBox->Controls->Add(this->KyLabel);
			this->ScalingGroupBox->Controls->Add(this->KzTextBox);
			this->ScalingGroupBox->Controls->Add(this->KyTextBox);
			this->ScalingGroupBox->Controls->Add(this->KxTextBox);
			this->ScalingGroupBox->Controls->Add(this->KxLabel);
			this->ScalingGroupBox->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ScalingGroupBox->ForeColor = System::Drawing::Color::Black;
			this->ScalingGroupBox->Location = System::Drawing::Point(12, 799);
			this->ScalingGroupBox->Name = L"ScalingGroupBox";
			this->ScalingGroupBox->Size = System::Drawing::Size(472, 269);
			this->ScalingGroupBox->TabIndex = 2;
			this->ScalingGroupBox->TabStop = false;
			this->ScalingGroupBox->Text = L"Масштабирование";
			// 
			// ScalingButton
			// 
			this->ScalingButton->BackColor = System::Drawing::Color::YellowGreen;
			this->ScalingButton->Location = System::Drawing::Point(6, 173);
			this->ScalingButton->Name = L"ScalingButton";
			this->ScalingButton->Size = System::Drawing::Size(460, 71);
			this->ScalingButton->TabIndex = 1;
			this->ScalingButton->Text = L"Масштабировать";
			this->ScalingButton->UseVisualStyleBackColor = false;
			// 
			// KzLabel
			// 
			this->KzLabel->AutoSize = true;
			this->KzLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->KzLabel->Location = System::Drawing::Point(324, 78);
			this->KzLabel->Name = L"KzLabel";
			this->KzLabel->Size = System::Drawing::Size(55, 36);
			this->KzLabel->TabIndex = 5;
			this->KzLabel->Text = L"kz:";
			// 
			// KyLabel
			// 
			this->KyLabel->AutoSize = true;
			this->KyLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->KyLabel->Location = System::Drawing::Point(161, 78);
			this->KyLabel->Name = L"KyLabel";
			this->KyLabel->Size = System::Drawing::Size(55, 36);
			this->KyLabel->TabIndex = 4;
			this->KyLabel->Text = L"ky:";
			// 
			// KzTextBox
			// 
			this->KzTextBox->Location = System::Drawing::Point(330, 117);
			this->KzTextBox->Name = L"KzTextBox";
			this->KzTextBox->Size = System::Drawing::Size(136, 50);
			this->KzTextBox->TabIndex = 3;
			this->KzTextBox->Text = L"1";
			// 
			// KyTextBox
			// 
			this->KyTextBox->Location = System::Drawing::Point(166, 117);
			this->KyTextBox->Name = L"KyTextBox";
			this->KyTextBox->Size = System::Drawing::Size(136, 50);
			this->KyTextBox->TabIndex = 2;
			this->KyTextBox->Text = L"1";
			// 
			// KxTextBox
			// 
			this->KxTextBox->Location = System::Drawing::Point(6, 117);
			this->KxTextBox->Name = L"KxTextBox";
			this->KxTextBox->Size = System::Drawing::Size(136, 50);
			this->KxTextBox->TabIndex = 1;
			this->KxTextBox->Text = L"1";
			// 
			// KxLabel
			// 
			this->KxLabel->AutoSize = true;
			this->KxLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->KxLabel->Location = System::Drawing::Point(6, 78);
			this->KxLabel->Name = L"KxLabel";
			this->KxLabel->Size = System::Drawing::Size(54, 36);
			this->KxLabel->TabIndex = 1;
			this->KxLabel->Text = L"kx:";
			// 
			// ZeroButton
			// 
			this->ZeroButton->Font = (gcnew System::Drawing::Font(L"Arial Black", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ZeroButton->ForeColor = System::Drawing::Color::Black;
			this->ZeroButton->Location = System::Drawing::Point(12, 1074);
			this->ZeroButton->Name = L"ZeroButton";
			this->ZeroButton->Size = System::Drawing::Size(466, 64);
			this->ZeroButton->TabIndex = 3;
			this->ZeroButton->Text = L"Сброс";
			this->ZeroButton->UseVisualStyleBackColor = true;
			// 
			// ModelComboBox
			// 
			this->ModelComboBox->FormattingEnabled = true;
			this->ModelComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"куб" });
			this->ModelComboBox->Location = System::Drawing::Point(6, 76);
			this->ModelComboBox->Name = L"ModelComboBox";
			this->ModelComboBox->Size = System::Drawing::Size(449, 50);
			this->ModelComboBox->TabIndex = 4;
			// 
			// ModelGroupBox
			// 
			this->ModelGroupBox->BackColor = System::Drawing::Color::PeachPuff;
			this->ModelGroupBox->Controls->Add(this->ModelComboBox);
			this->ModelGroupBox->Font = (gcnew System::Drawing::Font(L"Arial", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ModelGroupBox->Location = System::Drawing::Point(12, 72);
			this->ModelGroupBox->Name = L"ModelGroupBox";
			this->ModelGroupBox->Size = System::Drawing::Size(472, 171);
			this->ModelGroupBox->TabIndex = 5;
			this->ModelGroupBox->TabStop = false;
			this->ModelGroupBox->Text = L"Модель";
			// 
			// MenuGroupBox
			// 
			this->MenuGroupBox->BackColor = System::Drawing::SystemColors::Window;
			this->MenuGroupBox->Controls->Add(this->ModelGroupBox);
			this->MenuGroupBox->Controls->Add(this->ZeroButton);
			this->MenuGroupBox->Controls->Add(this->RotationGroupBox);
			this->MenuGroupBox->Controls->Add(this->ScalingGroupBox);
			this->MenuGroupBox->Controls->Add(this->ShiftGroupBox);
			this->MenuGroupBox->Font = (gcnew System::Drawing::Font(L"Arial Black", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MenuGroupBox->ForeColor = System::Drawing::Color::YellowGreen;
			this->MenuGroupBox->Location = System::Drawing::Point(12, 12);
			this->MenuGroupBox->Name = L"MenuGroupBox";
			this->MenuGroupBox->Size = System::Drawing::Size(492, 1164);
			this->MenuGroupBox->TabIndex = 6;
			this->MenuGroupBox->TabStop = false;
			this->MenuGroupBox->Text = L"Меню";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(2169, 1187);
			this->Controls->Add(this->MenuGroupBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Form1";
			this->Text = L"Лабораторная работа №1";
			this->RotationGroupBox->ResumeLayout(false);
			this->RotationGroupBox->PerformLayout();
			this->ShiftGroupBox->ResumeLayout(false);
			this->ShiftGroupBox->PerformLayout();
			this->ScalingGroupBox->ResumeLayout(false);
			this->ScalingGroupBox->PerformLayout();
			this->ModelGroupBox->ResumeLayout(false);
			this->MenuGroupBox->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
