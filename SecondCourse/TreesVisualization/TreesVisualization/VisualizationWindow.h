#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
//#include <conio.h>

namespace TreesVisualization {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	#include "TreesLib.h"

	BinaryTree binaryTree;
	AVLTree avlTree;
	int mode = 0; // 0 - Binary   1 - AVL
	int iterativeMode = 0; // 0 - Прямой  1 - Симметричный 2 - Обратный

	int ArrayX[6][32] = { {625}, {313, 937}, {157, 469, 781, 1093}, {79, 235, 391, 547, 703, 859, 1015, 1171}, {40, 118, 196, 274, 352, 430, 508, 586, 664, 742, 820, 898, 976, 1054, 1132, 1210}, {20, 59, 98, 137, 176, 215, 254, 293, 332, 371, 410, 449, 488, 527, 566, 605, 644, 683, 722, 761, 800, 839, 878, 917, 956, 995, 1034, 1073, 1112, 1151, 1190, 1229} };
	int ArrayY[6] = {68, 138, 208, 278, 348, 418};

	/// <summary>
	/// Сводка для VisualizationWindow
	/// </summary>
	public ref class VisualizationWindow : public System::Windows::Forms::Form
	{
	public:
		VisualizationWindow(void)
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
		~VisualizationWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ background;
	private: System::Windows::Forms::PictureBox^ AVLTreeButtonOn;
	private: System::Windows::Forms::PictureBox^ AVLTreeButton;


	private: System::Windows::Forms::PictureBox^ BinaryTreeButton;
	private: System::Windows::Forms::PictureBox^ BinaryTreeButtonOn;
	private: System::Windows::Forms::PictureBox^ CreateTreeButton;
	private: System::Windows::Forms::PictureBox^ CreateTreeButtonOn;
	private: System::Windows::Forms::PictureBox^ InsertElementButton;
	private: System::Windows::Forms::PictureBox^ InsertElementButtonOn;
	private: System::Windows::Forms::PictureBox^ SearchElementButton;
	private: System::Windows::Forms::PictureBox^ SearchElementButtonOn;
	private: System::Windows::Forms::PictureBox^ DeleteElementButton;
	private: System::Windows::Forms::PictureBox^ DeleteElementButtonOn;
	private: System::Windows::Forms::PictureBox^ IterativeTreeButton;
	private: System::Windows::Forms::PictureBox^ IterativeTreeButtonOn;
	private: System::Windows::Forms::PictureBox^ MainTreeBox;


	private: System::Windows::Forms::PictureBox^ InsertElementBox;
	private: System::Windows::Forms::RichTextBox^ InsertElementTextBox;
	private: System::Windows::Forms::PictureBox^ InsertElementDoneButton;
	private: System::Windows::Forms::Label^ CountObjText;
	private: System::Windows::Forms::Label^ HeightTreeText;
	private: System::Windows::Forms::PictureBox^ DeleteElementBox;
	private: System::Windows::Forms::RichTextBox^ DeleteElementTextBox;
	private: System::Windows::Forms::PictureBox^ DeleteElementDoneButton;
	private: System::Windows::Forms::PictureBox^ InsertElementDoneButtonOn;
	private: System::Windows::Forms::PictureBox^ DeleteElementDoneButtonOn;
	private: System::Windows::Forms::PictureBox^ CreateEmptyTreeButton;
	private: System::Windows::Forms::PictureBox^ CreateEmptyTreeButtonOn;
	private: System::Windows::Forms::PictureBox^ CreateBinaryTreeButton;
	private: System::Windows::Forms::PictureBox^ CreateBinaryTreeButtonOn;
	private: System::Windows::Forms::PictureBox^ CreateAVLTreeButton;
	private: System::Windows::Forms::PictureBox^ CreateAVLTreeButtonOn;
	private: System::Windows::Forms::Label^ SymmetryTreeText;
	private: System::Windows::Forms::PictureBox^ PreIterativeTreeDoneButton;
	private: System::Windows::Forms::PictureBox^ PreIterativeTreeDoneButtonOn;
	private: System::Windows::Forms::RichTextBox^ IterativeTreeTextBox;
	private: System::Windows::Forms::PictureBox^ InIterativeTreeDoneButton;
	private: System::Windows::Forms::PictureBox^ InIterativeTreeDoneButtonOn;
	private: System::Windows::Forms::PictureBox^ PostIterativeTreeDoneButton;
	private: System::Windows::Forms::PictureBox^ PostIterativeTreeDoneButtonOn;
	private: System::Windows::Forms::PictureBox^ SearchElementBox;
	private: System::Windows::Forms::RichTextBox^ SearchElementTextBox;
	private: System::Windows::Forms::PictureBox^ SearchElementDoneButton;
	private: System::Windows::Forms::PictureBox^ SearchElementDoneButtonOn;
	private: System::Windows::Forms::RichTextBox^ SearchElementDoneTextBox;








	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(VisualizationWindow::typeid));
			this->background = (gcnew System::Windows::Forms::PictureBox());
			this->AVLTreeButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->AVLTreeButton = (gcnew System::Windows::Forms::PictureBox());
			this->BinaryTreeButton = (gcnew System::Windows::Forms::PictureBox());
			this->BinaryTreeButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->CreateTreeButton = (gcnew System::Windows::Forms::PictureBox());
			this->CreateTreeButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->InsertElementButton = (gcnew System::Windows::Forms::PictureBox());
			this->InsertElementButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->SearchElementButton = (gcnew System::Windows::Forms::PictureBox());
			this->SearchElementButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->DeleteElementButton = (gcnew System::Windows::Forms::PictureBox());
			this->DeleteElementButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->IterativeTreeButton = (gcnew System::Windows::Forms::PictureBox());
			this->IterativeTreeButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->MainTreeBox = (gcnew System::Windows::Forms::PictureBox());
			this->InsertElementBox = (gcnew System::Windows::Forms::PictureBox());
			this->InsertElementTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->InsertElementDoneButton = (gcnew System::Windows::Forms::PictureBox());
			this->CountObjText = (gcnew System::Windows::Forms::Label());
			this->HeightTreeText = (gcnew System::Windows::Forms::Label());
			this->DeleteElementBox = (gcnew System::Windows::Forms::PictureBox());
			this->DeleteElementTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->DeleteElementDoneButton = (gcnew System::Windows::Forms::PictureBox());
			this->InsertElementDoneButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->DeleteElementDoneButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->CreateEmptyTreeButton = (gcnew System::Windows::Forms::PictureBox());
			this->CreateEmptyTreeButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->CreateBinaryTreeButton = (gcnew System::Windows::Forms::PictureBox());
			this->CreateBinaryTreeButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->CreateAVLTreeButton = (gcnew System::Windows::Forms::PictureBox());
			this->CreateAVLTreeButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->SymmetryTreeText = (gcnew System::Windows::Forms::Label());
			this->PreIterativeTreeDoneButton = (gcnew System::Windows::Forms::PictureBox());
			this->PreIterativeTreeDoneButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->IterativeTreeTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->InIterativeTreeDoneButton = (gcnew System::Windows::Forms::PictureBox());
			this->InIterativeTreeDoneButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->PostIterativeTreeDoneButton = (gcnew System::Windows::Forms::PictureBox());
			this->PostIterativeTreeDoneButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->SearchElementBox = (gcnew System::Windows::Forms::PictureBox());
			this->SearchElementTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SearchElementDoneButton = (gcnew System::Windows::Forms::PictureBox());
			this->SearchElementDoneButtonOn = (gcnew System::Windows::Forms::PictureBox());
			this->SearchElementDoneTextBox = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AVLTreeButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AVLTreeButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BinaryTreeButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BinaryTreeButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateTreeButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateTreeButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IterativeTreeButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IterativeTreeButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainTreeBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementDoneButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementDoneButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementDoneButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementDoneButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateEmptyTreeButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateEmptyTreeButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateBinaryTreeButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateBinaryTreeButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateAVLTreeButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateAVLTreeButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreIterativeTreeDoneButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreIterativeTreeDoneButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InIterativeTreeDoneButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InIterativeTreeDoneButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PostIterativeTreeDoneButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PostIterativeTreeDoneButtonOn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementDoneButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementDoneButtonOn))->BeginInit();
			this->SuspendLayout();
			// 
			// background
			// 
			this->background->BackColor = System::Drawing::SystemColors::Control;
			this->background->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"background.Image")));
			this->background->Location = System::Drawing::Point(0, 0);
			this->background->Name = L"background";
			this->background->Size = System::Drawing::Size(1280, 720);
			this->background->TabIndex = 0;
			this->background->TabStop = false;
			// 
			// AVLTreeButtonOn
			// 
			this->AVLTreeButtonOn->BackColor = System::Drawing::Color::White;
			this->AVLTreeButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AVLTreeButtonOn.Image")));
			this->AVLTreeButtonOn->Location = System::Drawing::Point(91, 540);
			this->AVLTreeButtonOn->Name = L"AVLTreeButtonOn";
			this->AVLTreeButtonOn->Size = System::Drawing::Size(54, 20);
			this->AVLTreeButtonOn->TabIndex = 1;
			this->AVLTreeButtonOn->TabStop = false;
			this->AVLTreeButtonOn->Visible = false;
			// 
			// AVLTreeButton
			// 
			this->AVLTreeButton->BackColor = System::Drawing::Color::White;
			this->AVLTreeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AVLTreeButton.Image")));
			this->AVLTreeButton->Location = System::Drawing::Point(91, 540);
			this->AVLTreeButton->Name = L"AVLTreeButton";
			this->AVLTreeButton->Size = System::Drawing::Size(54, 20);
			this->AVLTreeButton->TabIndex = 2;
			this->AVLTreeButton->TabStop = false;
			this->AVLTreeButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::AVLTreeButton_Click);
			// 
			// BinaryTreeButton
			// 
			this->BinaryTreeButton->BackColor = System::Drawing::Color::White;
			this->BinaryTreeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BinaryTreeButton.Image")));
			this->BinaryTreeButton->Location = System::Drawing::Point(15, 540);
			this->BinaryTreeButton->Name = L"BinaryTreeButton";
			this->BinaryTreeButton->Size = System::Drawing::Size(71, 20);
			this->BinaryTreeButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->BinaryTreeButton->TabIndex = 3;
			this->BinaryTreeButton->TabStop = false;
			this->BinaryTreeButton->Visible = false;
			this->BinaryTreeButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::BinaryTreeButton_Click);
			// 
			// BinaryTreeButtonOn
			// 
			this->BinaryTreeButtonOn->BackColor = System::Drawing::Color::White;
			this->BinaryTreeButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BinaryTreeButtonOn.Image")));
			this->BinaryTreeButtonOn->Location = System::Drawing::Point(15, 540);
			this->BinaryTreeButtonOn->Name = L"BinaryTreeButtonOn";
			this->BinaryTreeButtonOn->Size = System::Drawing::Size(71, 20);
			this->BinaryTreeButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->BinaryTreeButtonOn->TabIndex = 4;
			this->BinaryTreeButtonOn->TabStop = false;
			// 
			// CreateTreeButton
			// 
			this->CreateTreeButton->BackColor = System::Drawing::Color::White;
			this->CreateTreeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateTreeButton.Image")));
			this->CreateTreeButton->Location = System::Drawing::Point(15, 565);
			this->CreateTreeButton->Name = L"CreateTreeButton";
			this->CreateTreeButton->Size = System::Drawing::Size(130, 20);
			this->CreateTreeButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CreateTreeButton->TabIndex = 5;
			this->CreateTreeButton->TabStop = false;
			this->CreateTreeButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::CreateTreeButton_Click);
			// 
			// CreateTreeButtonOn
			// 
			this->CreateTreeButtonOn->BackColor = System::Drawing::Color::White;
			this->CreateTreeButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateTreeButtonOn.Image")));
			this->CreateTreeButtonOn->Location = System::Drawing::Point(15, 565);
			this->CreateTreeButtonOn->Name = L"CreateTreeButtonOn";
			this->CreateTreeButtonOn->Size = System::Drawing::Size(130, 20);
			this->CreateTreeButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CreateTreeButtonOn->TabIndex = 6;
			this->CreateTreeButtonOn->TabStop = false;
			this->CreateTreeButtonOn->Visible = false;
			this->CreateTreeButtonOn->Click += gcnew System::EventHandler(this, &VisualizationWindow::CreateTreeButtonOn_Click);
			// 
			// InsertElementButton
			// 
			this->InsertElementButton->BackColor = System::Drawing::Color::White;
			this->InsertElementButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InsertElementButton.Image")));
			this->InsertElementButton->Location = System::Drawing::Point(15, 590);
			this->InsertElementButton->Name = L"InsertElementButton";
			this->InsertElementButton->Size = System::Drawing::Size(130, 20);
			this->InsertElementButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InsertElementButton->TabIndex = 7;
			this->InsertElementButton->TabStop = false;
			this->InsertElementButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::InsertElementButton_Click);
			// 
			// InsertElementButtonOn
			// 
			this->InsertElementButtonOn->BackColor = System::Drawing::Color::White;
			this->InsertElementButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InsertElementButtonOn.Image")));
			this->InsertElementButtonOn->Location = System::Drawing::Point(15, 590);
			this->InsertElementButtonOn->Name = L"InsertElementButtonOn";
			this->InsertElementButtonOn->Size = System::Drawing::Size(130, 20);
			this->InsertElementButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InsertElementButtonOn->TabIndex = 8;
			this->InsertElementButtonOn->TabStop = false;
			this->InsertElementButtonOn->Visible = false;
			this->InsertElementButtonOn->Click += gcnew System::EventHandler(this, &VisualizationWindow::InsertElementButtonOn_Click);
			// 
			// SearchElementButton
			// 
			this->SearchElementButton->BackColor = System::Drawing::Color::White;
			this->SearchElementButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SearchElementButton.Image")));
			this->SearchElementButton->Location = System::Drawing::Point(15, 615);
			this->SearchElementButton->Name = L"SearchElementButton";
			this->SearchElementButton->Size = System::Drawing::Size(130, 20);
			this->SearchElementButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->SearchElementButton->TabIndex = 9;
			this->SearchElementButton->TabStop = false;
			this->SearchElementButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::SearchElementButton_Click);
			// 
			// SearchElementButtonOn
			// 
			this->SearchElementButtonOn->BackColor = System::Drawing::Color::White;
			this->SearchElementButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SearchElementButtonOn.Image")));
			this->SearchElementButtonOn->Location = System::Drawing::Point(15, 615);
			this->SearchElementButtonOn->Name = L"SearchElementButtonOn";
			this->SearchElementButtonOn->Size = System::Drawing::Size(130, 20);
			this->SearchElementButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->SearchElementButtonOn->TabIndex = 10;
			this->SearchElementButtonOn->TabStop = false;
			this->SearchElementButtonOn->Visible = false;
			this->SearchElementButtonOn->Click += gcnew System::EventHandler(this, &VisualizationWindow::SearchElementButtonOn_Click);
			// 
			// DeleteElementButton
			// 
			this->DeleteElementButton->BackColor = System::Drawing::Color::White;
			this->DeleteElementButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteElementButton.Image")));
			this->DeleteElementButton->Location = System::Drawing::Point(15, 640);
			this->DeleteElementButton->Name = L"DeleteElementButton";
			this->DeleteElementButton->Size = System::Drawing::Size(130, 20);
			this->DeleteElementButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->DeleteElementButton->TabIndex = 11;
			this->DeleteElementButton->TabStop = false;
			this->DeleteElementButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::DeleteElementButton_Click);
			// 
			// DeleteElementButtonOn
			// 
			this->DeleteElementButtonOn->BackColor = System::Drawing::Color::White;
			this->DeleteElementButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteElementButtonOn.Image")));
			this->DeleteElementButtonOn->Location = System::Drawing::Point(15, 640);
			this->DeleteElementButtonOn->Name = L"DeleteElementButtonOn";
			this->DeleteElementButtonOn->Size = System::Drawing::Size(130, 20);
			this->DeleteElementButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->DeleteElementButtonOn->TabIndex = 12;
			this->DeleteElementButtonOn->TabStop = false;
			this->DeleteElementButtonOn->Visible = false;
			this->DeleteElementButtonOn->Click += gcnew System::EventHandler(this, &VisualizationWindow::DeleteElementButtonOn_Click);
			// 
			// IterativeTreeButton
			// 
			this->IterativeTreeButton->BackColor = System::Drawing::Color::White;
			this->IterativeTreeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IterativeTreeButton.Image")));
			this->IterativeTreeButton->Location = System::Drawing::Point(15, 665);
			this->IterativeTreeButton->Name = L"IterativeTreeButton";
			this->IterativeTreeButton->Size = System::Drawing::Size(130, 20);
			this->IterativeTreeButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->IterativeTreeButton->TabIndex = 13;
			this->IterativeTreeButton->TabStop = false;
			this->IterativeTreeButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::IterativeTreeButton_Click);
			// 
			// IterativeTreeButtonOn
			// 
			this->IterativeTreeButtonOn->BackColor = System::Drawing::Color::White;
			this->IterativeTreeButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IterativeTreeButtonOn.Image")));
			this->IterativeTreeButtonOn->Location = System::Drawing::Point(15, 665);
			this->IterativeTreeButtonOn->Name = L"IterativeTreeButtonOn";
			this->IterativeTreeButtonOn->Size = System::Drawing::Size(130, 20);
			this->IterativeTreeButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->IterativeTreeButtonOn->TabIndex = 14;
			this->IterativeTreeButtonOn->TabStop = false;
			this->IterativeTreeButtonOn->Visible = false;
			this->IterativeTreeButtonOn->Click += gcnew System::EventHandler(this, &VisualizationWindow::IterativeTreeButtonOn_Click);
			// 
			// MainTreeBox
			// 
			this->MainTreeBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->MainTreeBox->Location = System::Drawing::Point(0, 0);
			this->MainTreeBox->Name = L"MainTreeBox";
			this->MainTreeBox->Size = System::Drawing::Size(1280, 515);
			this->MainTreeBox->TabIndex = 16;
			this->MainTreeBox->TabStop = false;
			this->MainTreeBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VisualizationWindow::MainTreeBox_Paint);
			// 
			// InsertElementBox
			// 
			this->InsertElementBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->InsertElementBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InsertElementBox.Image")));
			this->InsertElementBox->Location = System::Drawing::Point(155, 590);
			this->InsertElementBox->Name = L"InsertElementBox";
			this->InsertElementBox->Size = System::Drawing::Size(100, 20);
			this->InsertElementBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InsertElementBox->TabIndex = 17;
			this->InsertElementBox->TabStop = false;
			this->InsertElementBox->Visible = false;
			// 
			// InsertElementTextBox
			// 
			this->InsertElementTextBox->BackColor = System::Drawing::Color::White;
			this->InsertElementTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->InsertElementTextBox->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InsertElementTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->InsertElementTextBox->Location = System::Drawing::Point(160, 590);
			this->InsertElementTextBox->MaxLength = 3;
			this->InsertElementTextBox->Multiline = false;
			this->InsertElementTextBox->Name = L"InsertElementTextBox";
			this->InsertElementTextBox->Size = System::Drawing::Size(90, 20);
			this->InsertElementTextBox->TabIndex = 24;
			this->InsertElementTextBox->Text = L"";
			this->InsertElementTextBox->Visible = false;
			this->InsertElementTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &VisualizationWindow::InsertElementTextBox_KeyPress);
			// 
			// InsertElementDoneButton
			// 
			this->InsertElementDoneButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->InsertElementDoneButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InsertElementDoneButton.Image")));
			this->InsertElementDoneButton->Location = System::Drawing::Point(263, 590);
			this->InsertElementDoneButton->Margin = System::Windows::Forms::Padding(5);
			this->InsertElementDoneButton->Name = L"InsertElementDoneButton";
			this->InsertElementDoneButton->Size = System::Drawing::Size(71, 20);
			this->InsertElementDoneButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InsertElementDoneButton->TabIndex = 19;
			this->InsertElementDoneButton->TabStop = false;
			this->InsertElementDoneButton->Visible = false;
			this->InsertElementDoneButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::InsertElementDoneButton_MouseDown);
			this->InsertElementDoneButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::InsertElementDoneButton_MouseUp);
			// 
			// CountObjText
			// 
			this->CountObjText->AutoSize = true;
			this->CountObjText->BackColor = System::Drawing::Color::White;
			this->CountObjText->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CountObjText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->CountObjText->Location = System::Drawing::Point(1209, 630);
			this->CountObjText->Name = L"CountObjText";
			this->CountObjText->Size = System::Drawing::Size(19, 19);
			this->CountObjText->TabIndex = 20;
			this->CountObjText->Text = L"0";
			// 
			// HeightTreeText
			// 
			this->HeightTreeText->AutoSize = true;
			this->HeightTreeText->BackColor = System::Drawing::Color::White;
			this->HeightTreeText->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HeightTreeText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->HeightTreeText->Location = System::Drawing::Point(1155, 649);
			this->HeightTreeText->Name = L"HeightTreeText";
			this->HeightTreeText->Size = System::Drawing::Size(19, 19);
			this->HeightTreeText->TabIndex = 22;
			this->HeightTreeText->Text = L"0";
			// 
			// DeleteElementBox
			// 
			this->DeleteElementBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->DeleteElementBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteElementBox.Image")));
			this->DeleteElementBox->Location = System::Drawing::Point(155, 640);
			this->DeleteElementBox->Name = L"DeleteElementBox";
			this->DeleteElementBox->Size = System::Drawing::Size(100, 20);
			this->DeleteElementBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->DeleteElementBox->TabIndex = 23;
			this->DeleteElementBox->TabStop = false;
			this->DeleteElementBox->Visible = false;
			// 
			// DeleteElementTextBox
			// 
			this->DeleteElementTextBox->BackColor = System::Drawing::Color::White;
			this->DeleteElementTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DeleteElementTextBox->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DeleteElementTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->DeleteElementTextBox->Location = System::Drawing::Point(160, 640);
			this->DeleteElementTextBox->MaxLength = 3;
			this->DeleteElementTextBox->Multiline = false;
			this->DeleteElementTextBox->Name = L"DeleteElementTextBox";
			this->DeleteElementTextBox->Size = System::Drawing::Size(90, 20);
			this->DeleteElementTextBox->TabIndex = 24;
			this->DeleteElementTextBox->Text = L"";
			this->DeleteElementTextBox->Visible = false;
			this->DeleteElementTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &VisualizationWindow::DeleteElementTextBox_KeyPress);
			// 
			// DeleteElementDoneButton
			// 
			this->DeleteElementDoneButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->DeleteElementDoneButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteElementDoneButton.Image")));
			this->DeleteElementDoneButton->Location = System::Drawing::Point(263, 640);
			this->DeleteElementDoneButton->Margin = System::Windows::Forms::Padding(5);
			this->DeleteElementDoneButton->Name = L"DeleteElementDoneButton";
			this->DeleteElementDoneButton->Size = System::Drawing::Size(71, 20);
			this->DeleteElementDoneButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->DeleteElementDoneButton->TabIndex = 25;
			this->DeleteElementDoneButton->TabStop = false;
			this->DeleteElementDoneButton->Visible = false;
			this->DeleteElementDoneButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::DeleteElementDoneButton_MouseDown);
			this->DeleteElementDoneButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::DeleteElementDoneButton_MouseUp);
			// 
			// InsertElementDoneButtonOn
			// 
			this->InsertElementDoneButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->InsertElementDoneButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InsertElementDoneButtonOn.Image")));
			this->InsertElementDoneButtonOn->Location = System::Drawing::Point(263, 590);
			this->InsertElementDoneButtonOn->Name = L"InsertElementDoneButtonOn";
			this->InsertElementDoneButtonOn->Size = System::Drawing::Size(71, 20);
			this->InsertElementDoneButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InsertElementDoneButtonOn->TabIndex = 26;
			this->InsertElementDoneButtonOn->TabStop = false;
			this->InsertElementDoneButtonOn->Visible = false;
			// 
			// DeleteElementDoneButtonOn
			// 
			this->DeleteElementDoneButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->DeleteElementDoneButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteElementDoneButtonOn.Image")));
			this->DeleteElementDoneButtonOn->Location = System::Drawing::Point(263, 640);
			this->DeleteElementDoneButtonOn->Name = L"DeleteElementDoneButtonOn";
			this->DeleteElementDoneButtonOn->Size = System::Drawing::Size(71, 20);
			this->DeleteElementDoneButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->DeleteElementDoneButtonOn->TabIndex = 27;
			this->DeleteElementDoneButtonOn->TabStop = false;
			this->DeleteElementDoneButtonOn->Visible = false;
			// 
			// CreateEmptyTreeButton
			// 
			this->CreateEmptyTreeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->CreateEmptyTreeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateEmptyTreeButton.Image")));
			this->CreateEmptyTreeButton->Location = System::Drawing::Point(155, 565);
			this->CreateEmptyTreeButton->Name = L"CreateEmptyTreeButton";
			this->CreateEmptyTreeButton->Size = System::Drawing::Size(71, 20);
			this->CreateEmptyTreeButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CreateEmptyTreeButton->TabIndex = 28;
			this->CreateEmptyTreeButton->TabStop = false;
			this->CreateEmptyTreeButton->Visible = false;
			this->CreateEmptyTreeButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::CreateEmptyTreeButton_MouseDown);
			this->CreateEmptyTreeButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::CreateEmptyTreeButton_MouseUp);
			// 
			// CreateEmptyTreeButtonOn
			// 
			this->CreateEmptyTreeButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->CreateEmptyTreeButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateEmptyTreeButtonOn.Image")));
			this->CreateEmptyTreeButtonOn->Location = System::Drawing::Point(155, 565);
			this->CreateEmptyTreeButtonOn->Name = L"CreateEmptyTreeButtonOn";
			this->CreateEmptyTreeButtonOn->Size = System::Drawing::Size(71, 20);
			this->CreateEmptyTreeButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CreateEmptyTreeButtonOn->TabIndex = 29;
			this->CreateEmptyTreeButtonOn->TabStop = false;
			this->CreateEmptyTreeButtonOn->Visible = false;
			// 
			// CreateBinaryTreeButton
			// 
			this->CreateBinaryTreeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->CreateBinaryTreeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateBinaryTreeButton.Image")));
			this->CreateBinaryTreeButton->Location = System::Drawing::Point(234, 565);
			this->CreateBinaryTreeButton->Margin = System::Windows::Forms::Padding(5);
			this->CreateBinaryTreeButton->Name = L"CreateBinaryTreeButton";
			this->CreateBinaryTreeButton->Size = System::Drawing::Size(71, 20);
			this->CreateBinaryTreeButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CreateBinaryTreeButton->TabIndex = 30;
			this->CreateBinaryTreeButton->TabStop = false;
			this->CreateBinaryTreeButton->Visible = false;
			this->CreateBinaryTreeButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::CreateBinaryTreeButton_MouseDown);
			this->CreateBinaryTreeButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::CreateBinaryTreeButton_MouseUp);
			// 
			// CreateBinaryTreeButtonOn
			// 
			this->CreateBinaryTreeButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->CreateBinaryTreeButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateBinaryTreeButtonOn.Image")));
			this->CreateBinaryTreeButtonOn->Location = System::Drawing::Point(234, 565);
			this->CreateBinaryTreeButtonOn->Name = L"CreateBinaryTreeButtonOn";
			this->CreateBinaryTreeButtonOn->Size = System::Drawing::Size(71, 20);
			this->CreateBinaryTreeButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CreateBinaryTreeButtonOn->TabIndex = 31;
			this->CreateBinaryTreeButtonOn->TabStop = false;
			this->CreateBinaryTreeButtonOn->Visible = false;
			// 
			// CreateAVLTreeButton
			// 
			this->CreateAVLTreeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->CreateAVLTreeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateAVLTreeButton.Image")));
			this->CreateAVLTreeButton->Location = System::Drawing::Point(313, 565);
			this->CreateAVLTreeButton->Margin = System::Windows::Forms::Padding(5);
			this->CreateAVLTreeButton->Name = L"CreateAVLTreeButton";
			this->CreateAVLTreeButton->Size = System::Drawing::Size(71, 20);
			this->CreateAVLTreeButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CreateAVLTreeButton->TabIndex = 32;
			this->CreateAVLTreeButton->TabStop = false;
			this->CreateAVLTreeButton->Visible = false;
			this->CreateAVLTreeButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::CreateAVLTreeButton_MouseDown);
			this->CreateAVLTreeButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::CreateAVLTreeButton_MouseUp);
			// 
			// CreateAVLTreeButtonOn
			// 
			this->CreateAVLTreeButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->CreateAVLTreeButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateAVLTreeButtonOn.Image")));
			this->CreateAVLTreeButtonOn->Location = System::Drawing::Point(313, 565);
			this->CreateAVLTreeButtonOn->Name = L"CreateAVLTreeButtonOn";
			this->CreateAVLTreeButtonOn->Size = System::Drawing::Size(71, 20);
			this->CreateAVLTreeButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CreateAVLTreeButtonOn->TabIndex = 33;
			this->CreateAVLTreeButtonOn->TabStop = false;
			this->CreateAVLTreeButtonOn->Visible = false;
			// 
			// SymmetryTreeText
			// 
			this->SymmetryTreeText->AutoSize = true;
			this->SymmetryTreeText->BackColor = System::Drawing::Color::White;
			this->SymmetryTreeText->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SymmetryTreeText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->SymmetryTreeText->Location = System::Drawing::Point(1148, 666);
			this->SymmetryTreeText->Name = L"SymmetryTreeText";
			this->SymmetryTreeText->Size = System::Drawing::Size(35, 19);
			this->SymmetryTreeText->TabIndex = 34;
			this->SymmetryTreeText->Text = L"нет";
			// 
			// PreIterativeTreeDoneButton
			// 
			this->PreIterativeTreeDoneButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->PreIterativeTreeDoneButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PreIterativeTreeDoneButton.Image")));
			this->PreIterativeTreeDoneButton->Location = System::Drawing::Point(155, 665);
			this->PreIterativeTreeDoneButton->Name = L"PreIterativeTreeDoneButton";
			this->PreIterativeTreeDoneButton->Size = System::Drawing::Size(115, 20);
			this->PreIterativeTreeDoneButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PreIterativeTreeDoneButton->TabIndex = 35;
			this->PreIterativeTreeDoneButton->TabStop = false;
			this->PreIterativeTreeDoneButton->Visible = false;
			this->PreIterativeTreeDoneButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::PreIterativeTreeDoneButton_Click);
			// 
			// PreIterativeTreeDoneButtonOn
			// 
			this->PreIterativeTreeDoneButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->PreIterativeTreeDoneButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PreIterativeTreeDoneButtonOn.Image")));
			this->PreIterativeTreeDoneButtonOn->Location = System::Drawing::Point(155, 665);
			this->PreIterativeTreeDoneButtonOn->Name = L"PreIterativeTreeDoneButtonOn";
			this->PreIterativeTreeDoneButtonOn->Size = System::Drawing::Size(115, 20);
			this->PreIterativeTreeDoneButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PreIterativeTreeDoneButtonOn->TabIndex = 36;
			this->PreIterativeTreeDoneButtonOn->TabStop = false;
			this->PreIterativeTreeDoneButtonOn->Visible = false;
			// 
			// IterativeTreeTextBox
			// 
			this->IterativeTreeTextBox->AcceptsTab = true;
			this->IterativeTreeTextBox->BackColor = System::Drawing::Color::White;
			this->IterativeTreeTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->IterativeTreeTextBox->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->IterativeTreeTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->IterativeTreeTextBox->HideSelection = false;
			this->IterativeTreeTextBox->Location = System::Drawing::Point(1053, 532);
			this->IterativeTreeTextBox->Name = L"IterativeTreeTextBox";
			this->IterativeTreeTextBox->ReadOnly = true;
			this->IterativeTreeTextBox->ShortcutsEnabled = false;
			this->IterativeTreeTextBox->Size = System::Drawing::Size(215, 61);
			this->IterativeTreeTextBox->TabIndex = 37;
			this->IterativeTreeTextBox->TabStop = false;
			this->IterativeTreeTextBox->Text = L"";
			// 
			// InIterativeTreeDoneButton
			// 
			this->InIterativeTreeDoneButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->InIterativeTreeDoneButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InIterativeTreeDoneButton.Image")));
			this->InIterativeTreeDoneButton->Location = System::Drawing::Point(278, 665);
			this->InIterativeTreeDoneButton->Margin = System::Windows::Forms::Padding(5);
			this->InIterativeTreeDoneButton->Name = L"InIterativeTreeDoneButton";
			this->InIterativeTreeDoneButton->Size = System::Drawing::Size(115, 20);
			this->InIterativeTreeDoneButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InIterativeTreeDoneButton->TabIndex = 38;
			this->InIterativeTreeDoneButton->TabStop = false;
			this->InIterativeTreeDoneButton->Visible = false;
			this->InIterativeTreeDoneButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::InIterativeTreeDoneButton_Click);
			// 
			// InIterativeTreeDoneButtonOn
			// 
			this->InIterativeTreeDoneButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->InIterativeTreeDoneButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InIterativeTreeDoneButtonOn.Image")));
			this->InIterativeTreeDoneButtonOn->Location = System::Drawing::Point(278, 665);
			this->InIterativeTreeDoneButtonOn->Margin = System::Windows::Forms::Padding(5);
			this->InIterativeTreeDoneButtonOn->Name = L"InIterativeTreeDoneButtonOn";
			this->InIterativeTreeDoneButtonOn->Size = System::Drawing::Size(115, 20);
			this->InIterativeTreeDoneButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InIterativeTreeDoneButtonOn->TabIndex = 39;
			this->InIterativeTreeDoneButtonOn->TabStop = false;
			this->InIterativeTreeDoneButtonOn->Visible = false;
			// 
			// PostIterativeTreeDoneButton
			// 
			this->PostIterativeTreeDoneButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->PostIterativeTreeDoneButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PostIterativeTreeDoneButton.Image")));
			this->PostIterativeTreeDoneButton->Location = System::Drawing::Point(403, 665);
			this->PostIterativeTreeDoneButton->Margin = System::Windows::Forms::Padding(5);
			this->PostIterativeTreeDoneButton->Name = L"PostIterativeTreeDoneButton";
			this->PostIterativeTreeDoneButton->Size = System::Drawing::Size(115, 20);
			this->PostIterativeTreeDoneButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PostIterativeTreeDoneButton->TabIndex = 40;
			this->PostIterativeTreeDoneButton->TabStop = false;
			this->PostIterativeTreeDoneButton->Visible = false;
			this->PostIterativeTreeDoneButton->Click += gcnew System::EventHandler(this, &VisualizationWindow::PostIterativeTreeDoneButton_Click);
			// 
			// PostIterativeTreeDoneButtonOn
			// 
			this->PostIterativeTreeDoneButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->PostIterativeTreeDoneButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PostIterativeTreeDoneButtonOn.Image")));
			this->PostIterativeTreeDoneButtonOn->Location = System::Drawing::Point(403, 665);
			this->PostIterativeTreeDoneButtonOn->Margin = System::Windows::Forms::Padding(5);
			this->PostIterativeTreeDoneButtonOn->Name = L"PostIterativeTreeDoneButtonOn";
			this->PostIterativeTreeDoneButtonOn->Size = System::Drawing::Size(115, 20);
			this->PostIterativeTreeDoneButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PostIterativeTreeDoneButtonOn->TabIndex = 41;
			this->PostIterativeTreeDoneButtonOn->TabStop = false;
			this->PostIterativeTreeDoneButtonOn->Visible = false;
			// 
			// SearchElementBox
			// 
			this->SearchElementBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->SearchElementBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SearchElementBox.Image")));
			this->SearchElementBox->Location = System::Drawing::Point(155, 615);
			this->SearchElementBox->Name = L"SearchElementBox";
			this->SearchElementBox->Size = System::Drawing::Size(100, 20);
			this->SearchElementBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->SearchElementBox->TabIndex = 42;
			this->SearchElementBox->TabStop = false;
			this->SearchElementBox->Visible = false;
			// 
			// SearchElementTextBox
			// 
			this->SearchElementTextBox->BackColor = System::Drawing::Color::White;
			this->SearchElementTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchElementTextBox->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SearchElementTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->SearchElementTextBox->Location = System::Drawing::Point(160, 615);
			this->SearchElementTextBox->MaxLength = 3;
			this->SearchElementTextBox->Multiline = false;
			this->SearchElementTextBox->Name = L"SearchElementTextBox";
			this->SearchElementTextBox->Size = System::Drawing::Size(90, 20);
			this->SearchElementTextBox->TabIndex = 24;
			this->SearchElementTextBox->Text = L"";
			this->SearchElementTextBox->Visible = false;
			// 
			// SearchElementDoneButton
			// 
			this->SearchElementDoneButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->SearchElementDoneButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SearchElementDoneButton.Image")));
			this->SearchElementDoneButton->Location = System::Drawing::Point(263, 615);
			this->SearchElementDoneButton->Name = L"SearchElementDoneButton";
			this->SearchElementDoneButton->Size = System::Drawing::Size(71, 20);
			this->SearchElementDoneButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->SearchElementDoneButton->TabIndex = 44;
			this->SearchElementDoneButton->TabStop = false;
			this->SearchElementDoneButton->Visible = false;
			this->SearchElementDoneButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::SearchElementDoneButton_MouseDown);
			this->SearchElementDoneButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VisualizationWindow::SearchElementDoneButton_MouseUp);
			// 
			// SearchElementDoneButtonOn
			// 
			this->SearchElementDoneButtonOn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->SearchElementDoneButtonOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SearchElementDoneButtonOn.Image")));
			this->SearchElementDoneButtonOn->Location = System::Drawing::Point(263, 615);
			this->SearchElementDoneButtonOn->Name = L"SearchElementDoneButtonOn";
			this->SearchElementDoneButtonOn->Size = System::Drawing::Size(71, 20);
			this->SearchElementDoneButtonOn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->SearchElementDoneButtonOn->TabIndex = 45;
			this->SearchElementDoneButtonOn->TabStop = false;
			this->SearchElementDoneButtonOn->Visible = false;
			// 
			// SearchElementDoneTextBox
			// 
			this->SearchElementDoneTextBox->AcceptsTab = true;
			this->SearchElementDoneTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->SearchElementDoneTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchElementDoneTextBox->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SearchElementDoneTextBox->ForeColor = System::Drawing::Color::White;
			this->SearchElementDoneTextBox->HideSelection = false;
			this->SearchElementDoneTextBox->Location = System::Drawing::Point(340, 618);
			this->SearchElementDoneTextBox->Multiline = false;
			this->SearchElementDoneTextBox->Name = L"SearchElementDoneTextBox";
			this->SearchElementDoneTextBox->ReadOnly = true;
			this->SearchElementDoneTextBox->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->SearchElementDoneTextBox->ShortcutsEnabled = false;
			this->SearchElementDoneTextBox->Size = System::Drawing::Size(178, 20);
			this->SearchElementDoneTextBox->TabIndex = 46;
			this->SearchElementDoneTextBox->TabStop = false;
			this->SearchElementDoneTextBox->Text = L"";
			this->SearchElementDoneTextBox->Visible = false;
			// 
			// VisualizationWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->SearchElementDoneTextBox);
			this->Controls->Add(this->SearchElementDoneButtonOn);
			this->Controls->Add(this->SearchElementDoneButton);
			this->Controls->Add(this->SearchElementTextBox);
			this->Controls->Add(this->SearchElementBox);
			this->Controls->Add(this->PostIterativeTreeDoneButtonOn);
			this->Controls->Add(this->PostIterativeTreeDoneButton);
			this->Controls->Add(this->InIterativeTreeDoneButtonOn);
			this->Controls->Add(this->InIterativeTreeDoneButton);
			this->Controls->Add(this->IterativeTreeTextBox);
			this->Controls->Add(this->PreIterativeTreeDoneButtonOn);
			this->Controls->Add(this->PreIterativeTreeDoneButton);
			this->Controls->Add(this->SymmetryTreeText);
			this->Controls->Add(this->CreateAVLTreeButtonOn);
			this->Controls->Add(this->CreateAVLTreeButton);
			this->Controls->Add(this->CreateBinaryTreeButtonOn);
			this->Controls->Add(this->CreateBinaryTreeButton);
			this->Controls->Add(this->CreateEmptyTreeButtonOn);
			this->Controls->Add(this->CreateEmptyTreeButton);
			this->Controls->Add(this->DeleteElementDoneButtonOn);
			this->Controls->Add(this->InsertElementDoneButtonOn);
			this->Controls->Add(this->DeleteElementDoneButton);
			this->Controls->Add(this->DeleteElementTextBox);
			this->Controls->Add(this->DeleteElementBox);
			this->Controls->Add(this->HeightTreeText);
			this->Controls->Add(this->CountObjText);
			this->Controls->Add(this->InsertElementDoneButton);
			this->Controls->Add(this->InsertElementTextBox);
			this->Controls->Add(this->InsertElementBox);
			this->Controls->Add(this->MainTreeBox);
			this->Controls->Add(this->IterativeTreeButtonOn);
			this->Controls->Add(this->IterativeTreeButton);
			this->Controls->Add(this->DeleteElementButtonOn);
			this->Controls->Add(this->DeleteElementButton);
			this->Controls->Add(this->SearchElementButtonOn);
			this->Controls->Add(this->SearchElementButton);
			this->Controls->Add(this->InsertElementButtonOn);
			this->Controls->Add(this->InsertElementButton);
			this->Controls->Add(this->CreateTreeButtonOn);
			this->Controls->Add(this->CreateTreeButton);
			this->Controls->Add(this->BinaryTreeButtonOn);
			this->Controls->Add(this->BinaryTreeButton);
			this->Controls->Add(this->AVLTreeButton);
			this->Controls->Add(this->AVLTreeButtonOn);
			this->Controls->Add(this->background);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1296, 759);
			this->MinimumSize = System::Drawing::Size(1296, 759);
			this->Name = L"VisualizationWindow";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Визуализация структуры данных - деревья";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AVLTreeButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AVLTreeButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BinaryTreeButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BinaryTreeButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateTreeButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateTreeButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IterativeTreeButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IterativeTreeButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainTreeBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementDoneButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementDoneButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InsertElementDoneButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteElementDoneButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateEmptyTreeButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateEmptyTreeButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateBinaryTreeButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateBinaryTreeButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateAVLTreeButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreateAVLTreeButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreIterativeTreeDoneButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreIterativeTreeDoneButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InIterativeTreeDoneButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InIterativeTreeDoneButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PostIterativeTreeDoneButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PostIterativeTreeDoneButtonOn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementDoneButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchElementDoneButtonOn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	//--------------------------------------[ Update ]--------------------------------------
	public: System::Void Update() {
		std::vector<int> iterative;
		int currentElement;
		switch (mode) {
		case 0: 
			CountObjText->Text = binaryTree.getCount().ToString(); 
			HeightTreeText->Text = binaryTree.getHeight().ToString();
			if (CountObjText->Text == "0") HeightTreeText->Text = "0";

			switch (binaryTree.isSymmetry()) {
			case 0: SymmetryTreeText->Text = "нет"; break;
			case 1: SymmetryTreeText->Text = "да"; break;
			}

			SearchElementDoneTextBox->Text = "";
			IterativeTreeTextBox->Text = "";
			switch (iterativeMode) {
			case 0: binaryTree.display(Tree::PREORDER, iterative); break;
			case 1: binaryTree.display(Tree::INORDER, iterative); break;
			case 2: binaryTree.display(Tree::POSTORDER, iterative); break;
			}

			for (int i = 0; i < Int32::Parse(CountObjText->Text); i++) {
				currentElement = *iterative.data();
				IterativeTreeTextBox->Text = IterativeTreeTextBox->Text+currentElement.ToString()+L" ";
				iterative.erase(iterative.begin());
			}
			break;
		case 1: 
			CountObjText->Text = avlTree.getCount().ToString();
			HeightTreeText->Text = avlTree.getHeight().ToString();
			if (CountObjText->Text == "0") HeightTreeText->Text = "0";

			switch (binaryTree.isSymmetry()) {
			case 0: SymmetryTreeText->Text = "нет"; break;
			case 1: SymmetryTreeText->Text = "да"; break;
			}

			IterativeTreeTextBox->Text = "";
			switch (iterativeMode) {
			case 0: avlTree.display(Tree::PREORDER, iterative); break;
			case 1: avlTree.display(Tree::INORDER, iterative); break;
			case 2: avlTree.display(Tree::POSTORDER, iterative); break;
			}

			for (int i = 0; i < Int32::Parse(CountObjText->Text); i++) {
				currentElement = *iterative.data();
				IterativeTreeTextBox->Text = IterativeTreeTextBox->Text + currentElement.ToString() + L" ";
				iterative.erase(iterative.begin());
			}
			break;
		}
		
		MainTreeBox->Refresh();
	}

	private: System::Void MainTreeBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen = gcnew Pen(Brushes::White, 2);
		SolidBrush^ brush = gcnew SolidBrush(Color::White);
		Image^ circle = Image::FromFile("../Resources/Circle.png");

		StringFormat^ format = gcnew StringFormat(StringFormatFlags::NoClip);
		format->Alignment = StringAlignment::Center;
		format->LineAlignment= StringAlignment::Center;

		std::vector<int> currentLevel;
		std::vector<int> vIndex;
		Int16 currentElement;
		Int16 currentIndex;
		currentLevel.push_back(-1);
		vIndex.push_back(0);

		switch (mode) {
		case 0:
			//Отрисовка линий
			for (int i = 0; i <= 5; i++) { // Levels
				currentLevel.clear();
				vIndex.clear();
				binaryTree.getLevel(i, currentLevel, vIndex);

				for (int j = 0; j <= pow(2, i) - 1; j++) {  // Elements
					if (!currentLevel.empty()) {
						currentElement = *currentLevel.data();
						currentIndex = *vIndex.data();
						if (currentIndex == j) {
							if (binaryTree.getCount() > 1 && i != 0) e->Graphics->DrawLine(pen, ArrayX[i - 1][j / 2] + 15, ArrayY[i - 1] + 15, ArrayX[i][j] + 15, ArrayY[i] + 15);
						}
						else continue;
						currentLevel.erase(currentLevel.begin());
						vIndex.erase(vIndex.begin());
					}
				}
				currentLevel.clear();
			}

			//Отрисовка элементов
			for (int i = 0; i <= 5; i++) { // Levels
				currentLevel.clear();
				vIndex.clear();
				binaryTree.getLevel(i, currentLevel, vIndex);

				for (int j = 0; j <= pow(2, i) - 1; j++) {
					if (!currentLevel.empty()) {
						currentElement = *currentLevel.data();
						currentIndex = *vIndex.data();
						if (currentIndex == j) {
							e->Graphics->DrawImage(circle, ArrayX[i][j], ArrayY[i], 30, 30);
							e->Graphics->DrawString(currentElement.ToString(), gcnew System::Drawing::Font(L"SF Pro Display", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point), brush, RectangleF(ArrayX[i][j], ArrayY[i], 30, 30), format);
						}
						else continue;
						currentLevel.erase(currentLevel.begin());
						vIndex.erase(vIndex.begin());
					}
				}
				currentLevel.clear();
			}
			break;
		case 1:
			//Отрисовка линий
			for (int i = 0; i <= 5; i++) { // Levels
				currentLevel.clear();
				vIndex.clear();
				avlTree.getLevel(i, currentLevel, vIndex);

				for (int j = 0; j <= pow(2, i) - 1; j++) {  // Elements
					if (!currentLevel.empty()) {
						currentElement = *currentLevel.data();
						currentIndex = *vIndex.data();
						if (currentIndex == j) {
							if (avlTree.getCount() > 1 && i != 0) e->Graphics->DrawLine(pen, ArrayX[i - 1][j / 2] + 15, ArrayY[i - 1] + 15, ArrayX[i][j] + 15, ArrayY[i] + 15);
						}
						else continue;
						currentLevel.erase(currentLevel.begin());
						vIndex.erase(vIndex.begin());
					}
				}
				currentLevel.clear();
			}

			//Отрисовка элементов
			for (int i = 0; i <= 5; i++) { // Levels
				currentLevel.clear();
				vIndex.clear();
				avlTree.getLevel(i, currentLevel, vIndex);

				for (int j = 0; j <= pow(2, i) - 1; j++) {
					if (!currentLevel.empty()) {
						currentElement = *currentLevel.data();
						currentIndex = *vIndex.data();
						if (currentIndex == j) {
							e->Graphics->DrawImage(circle, ArrayX[i][j], ArrayY[i], 30, 30);
							e->Graphics->DrawString(currentElement.ToString(), gcnew System::Drawing::Font(L"SF Pro Display", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point), brush, RectangleF(ArrayX[i][j], ArrayY[i] + 1, 30, 30), format);
						}
						else continue;
						currentLevel.erase(currentLevel.begin());
						vIndex.erase(vIndex.begin());
					}
				}
				currentLevel.clear();
			}
			break;
		}


		Image^ Number1 = Image::FromFile("../Resources/-1-.png");
		Image^ Number2 = Image::FromFile("../Resources/-2-.png");
		Image^ Number3 = Image::FromFile("../Resources/-3-.png");
		Image^ Number4 = Image::FromFile("../Resources/-4-.png");
		Image^ Number5 = Image::FromFile("../Resources/-5-.png");
		Image^ Number6 = Image::FromFile("../Resources/-6-.png");
		Image^ Root = Image::FromFile("../Resources/Root.png");

		if (CountObjText->Text != "0") {
			e->Graphics->DrawImage(Root, 620, 40, 39, 23);
		}

		if (HeightTreeText->Text == "1" && CountObjText->Text != "0") {
			e->Graphics->DrawImage(Number1, 0, ArrayY[0] + 11, 15, 8);
		}
		if (HeightTreeText->Text == "2") {
			e->Graphics->DrawImage(Number1, 0, ArrayY[0]+ 11, 15, 8);
			e->Graphics->DrawImage(Number2, 0, ArrayY[1]+ 11, 15, 8);
		}
		if (HeightTreeText->Text == "3") {
			e->Graphics->DrawImage(Number1, 0, ArrayY[0] + 11, 15, 8);
			e->Graphics->DrawImage(Number2, 0, ArrayY[1] + 11, 15, 8);
			e->Graphics->DrawImage(Number3, 0, ArrayY[2] + 11, 15, 8);
		}
		if (HeightTreeText->Text == "4") {
			e->Graphics->DrawImage(Number1, 0, ArrayY[0] + 11, 15, 8);
			e->Graphics->DrawImage(Number2, 0, ArrayY[1] + 11, 15, 8);
			e->Graphics->DrawImage(Number3, 0, ArrayY[2] + 11, 15, 8);
			e->Graphics->DrawImage(Number4, 0, ArrayY[3] + 11, 15, 8);
		}
		if (HeightTreeText->Text == "5") {
			e->Graphics->DrawImage(Number1, 0, ArrayY[0] + 11, 15, 8);
			e->Graphics->DrawImage(Number2, 0, ArrayY[1] + 11, 15, 8);
			e->Graphics->DrawImage(Number3, 0, ArrayY[2] + 11, 15, 8);
			e->Graphics->DrawImage(Number4, 0, ArrayY[3] + 11, 15, 8);
			e->Graphics->DrawImage(Number5, 0, ArrayY[4] + 11, 15, 8);
		}
		if (HeightTreeText->Text == "6") {
			e->Graphics->DrawImage(Number1, 0, ArrayY[0] + 11, 15, 8);
			e->Graphics->DrawImage(Number2, 0, ArrayY[1] + 11, 15, 8);
			e->Graphics->DrawImage(Number3, 0, ArrayY[2] + 11, 15, 8);
			e->Graphics->DrawImage(Number4, 0, ArrayY[3] + 11, 15, 8);
			e->Graphics->DrawImage(Number5, 0, ArrayY[4] + 11, 15, 8);
			e->Graphics->DrawImage(Number6, 0, ArrayY[5] + 11, 15, 8);
		}
	}





	//--------------------------------------[ Forms restrict ]--------------------------------------
	private: System::Void InsertElementTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char number = e->KeyChar;
		if (!Char::IsDigit(number)) {
			e->Handled = true;
		}
	}

	private: System::Void DeleteElementTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char number = e->KeyChar;
		if (!Char::IsDigit(number)) {
			e->Handled = true;
		}
	}





	//--------------------------------------[ Choose tree ]--------------------------------------
	private: System::Void BinaryTreeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		BinaryTreeButton->Visible = false;
		BinaryTreeButtonOn->Visible = true;
		AVLTreeButton->Visible = true;
		AVLTreeButtonOn->Visible = false;
		mode = 0;
		Update();
	}
	private: System::Void AVLTreeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		BinaryTreeButton->Visible = true;
		BinaryTreeButtonOn->Visible = false;
		AVLTreeButton->Visible = false;
		AVLTreeButtonOn->Visible = true;
		mode = 1;
		Update();
	}





	//--------------------------------------[ Create tree ]--------------------------------------
	private: System::Void CreateTreeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateTreeButton->Visible = false;
		CreateTreeButtonOn->Visible = true;
		InsertElementButton->Visible = true;
		InsertElementButtonOn->Visible = false;
		SearchElementButton->Visible = true;
		SearchElementButtonOn->Visible = false;
		DeleteElementButton->Visible = true;
		DeleteElementButtonOn->Visible = false;
		IterativeTreeButton->Visible = true;
		IterativeTreeButtonOn->Visible = false;

		CreateEmptyTreeButton->Visible = true;
		CreateBinaryTreeButton->Visible = true;
		CreateAVLTreeButton->Visible = true;

		InsertElementBox->Visible = false;
		InsertElementTextBox->Visible = false;
		InsertElementDoneButton->Visible = false;

		SearchElementBox->Visible = false;
		SearchElementTextBox->Visible = false;
		SearchElementDoneButton->Visible = false;
		SearchElementDoneTextBox->Visible = false;

		DeleteElementBox->Visible = false;
		DeleteElementTextBox->Visible = false;
		DeleteElementDoneButton->Visible = false;

		PreIterativeTreeDoneButton->Visible = false;
		InIterativeTreeDoneButton->Visible = false;
		PostIterativeTreeDoneButton->Visible = false;
		PreIterativeTreeDoneButtonOn->Visible = false;
		InIterativeTreeDoneButtonOn->Visible = false;
		PostIterativeTreeDoneButtonOn->Visible = false;

	}
	private: System::Void CreateTreeButtonOn_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateTreeButton->Visible = true;
		CreateTreeButtonOn->Visible = false;

		CreateEmptyTreeButton->Visible = false;
		CreateBinaryTreeButton->Visible = false;
		CreateAVLTreeButton->Visible = false;
	}

	private: System::Void CreateEmptyTreeButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		CreateEmptyTreeButton->Visible = false;
		CreateEmptyTreeButtonOn->Visible = true;

		switch (mode) {
		case 0:
			binaryTree.empty();
			break;
		case 1:
			avlTree.empty();
			break;
		}
		
		Update();
	}
	private: System::Void CreateEmptyTreeButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		CreateEmptyTreeButton->Visible = true;
		CreateEmptyTreeButtonOn->Visible = false;
	}

	private: System::Void CreateBinaryTreeButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		CreateBinaryTreeButton->Visible = false;
		CreateBinaryTreeButtonOn->Visible = true;

		mode = 0;
		BinaryTreeButton->Visible = false;
		BinaryTreeButtonOn->Visible = true;
		AVLTreeButton->Visible = true;
		AVLTreeButtonOn->Visible = false;

		srand((unsigned)time(0));
		int random_integer;
		int lowest = 1;
		int highest = 999;
		int range = (highest - lowest) + 1;

		binaryTree.empty();
		for (int i = 0; i < 25; i++) {
			random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));
			TreesVisualization::binaryTree.insert(random_integer);
		}
		Update();
	}
	private: System::Void CreateBinaryTreeButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		CreateBinaryTreeButton->Visible = true;
		CreateBinaryTreeButtonOn->Visible = false;
	}

	private: System::Void CreateAVLTreeButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		CreateAVLTreeButton->Visible = false;
		CreateAVLTreeButtonOn->Visible = true;

		mode = 1;
		BinaryTreeButton->Visible = true;
		BinaryTreeButtonOn->Visible = false;
		AVLTreeButton->Visible = false;
		AVLTreeButtonOn->Visible = true;

		srand((unsigned)time(0));
		int random_integer;
		int lowest = 1;
		int highest = 999;
		int range = (highest - lowest) + 1;

		avlTree.empty();
		for (int i = 0; i < 25; i++) {
			random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));
			TreesVisualization::avlTree.AVLTree::insert(random_integer);
		}
		Update();
	}
	private: System::Void CreateAVLTreeButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		CreateAVLTreeButton->Visible = true;
		CreateAVLTreeButtonOn->Visible = false;
	}





	//--------------------------------------[ Insert element ]--------------------------------------
	private: System::Void InsertElementButton_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateTreeButton->Visible = true;
		CreateTreeButtonOn->Visible = false;
		InsertElementButton->Visible = false;
		InsertElementButtonOn->Visible = true;
		SearchElementButton->Visible = true;
		SearchElementButtonOn->Visible = false;
		DeleteElementButton->Visible = true;
		DeleteElementButtonOn->Visible = false;
		IterativeTreeButton->Visible = true;
		IterativeTreeButtonOn->Visible = false;

		CreateEmptyTreeButton->Visible = false;
		CreateBinaryTreeButton->Visible = false;
		CreateAVLTreeButton->Visible = false;

		InsertElementTextBox->Visible = true;
		InsertElementBox->Visible = true;
		InsertElementDoneButton->Visible = true;

		SearchElementBox->Visible = false;
		SearchElementTextBox->Visible = false;
		SearchElementDoneButton->Visible = false;
		SearchElementDoneTextBox->Visible = false;

		DeleteElementBox->Visible = false;
		DeleteElementTextBox->Visible = false;
		DeleteElementDoneButton->Visible = false;

		PreIterativeTreeDoneButton->Visible = false;
		InIterativeTreeDoneButton->Visible = false;
		PostIterativeTreeDoneButton->Visible = false;
		PreIterativeTreeDoneButtonOn->Visible = false;
		InIterativeTreeDoneButtonOn->Visible = false;
		PostIterativeTreeDoneButtonOn->Visible = false;
	}
	private: System::Void InsertElementButtonOn_Click(System::Object^ sender, System::EventArgs^ e) {
		InsertElementButton->Visible = true;
		InsertElementButtonOn->Visible = false;

		InsertElementBox->Visible = false;
		InsertElementTextBox->Visible = false;
		InsertElementDoneButton->Visible = false;
	}

	private: System::Void InsertElementDoneButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		InsertElementDoneButton->Visible = false;
		InsertElementDoneButtonOn->Visible = true;
		switch (mode) {
		case 0:
			if (InsertElementTextBox->Text != "" && InsertElementTextBox->Text != " " && InsertElementTextBox->Text != "  " && InsertElementTextBox->Text != "   ") {
				TreesVisualization::binaryTree.insert(Int32::Parse(InsertElementTextBox->Text));
				Update();
				InsertElementTextBox->Text = "";
			}
			break;
		case 1:
			if (InsertElementTextBox->Text != "" && InsertElementTextBox->Text != " " && InsertElementTextBox->Text != "  " && InsertElementTextBox->Text != "   ") {
				TreesVisualization::avlTree.insert(Int32::Parse(InsertElementTextBox->Text));
				Update();
				InsertElementTextBox->Text = "";
			}
			break;
		}
	}
	private: System::Void InsertElementDoneButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		InsertElementDoneButton->Visible = true;
		InsertElementDoneButtonOn->Visible = false;
	}





	//--------------------------------------[ Search element ]--------------------------------------
	private: System::Void SearchElementButton_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateTreeButton->Visible = true;
		CreateTreeButtonOn->Visible = false;
		InsertElementButton->Visible = true;
		InsertElementButtonOn->Visible = false;
		SearchElementButton->Visible = false;
		SearchElementButtonOn->Visible = true;
		DeleteElementButton->Visible = true;
		DeleteElementButtonOn->Visible = false;
		IterativeTreeButton->Visible = true;
		IterativeTreeButtonOn->Visible = false;

		CreateEmptyTreeButton->Visible = false;
		CreateBinaryTreeButton->Visible = false;
		CreateAVLTreeButton->Visible = false;

		InsertElementBox->Visible = false;
		InsertElementTextBox->Visible = false;
		InsertElementDoneButton->Visible = false;

		SearchElementTextBox->Visible = true;
		SearchElementBox->Visible = true;
		SearchElementDoneButton->Visible = true;
		SearchElementDoneTextBox->Visible = true;

		DeleteElementBox->Visible = false;
		DeleteElementTextBox->Visible = false;
		DeleteElementDoneButton->Visible = false;

		PreIterativeTreeDoneButton->Visible = false;
		InIterativeTreeDoneButton->Visible = false;
		PostIterativeTreeDoneButton->Visible = false;
		PreIterativeTreeDoneButtonOn->Visible = false;
		InIterativeTreeDoneButtonOn->Visible = false;
		PostIterativeTreeDoneButtonOn->Visible = false;
	}
	private: System::Void SearchElementButtonOn_Click(System::Object^ sender, System::EventArgs^ e) {
		SearchElementButton->Visible = true;
		SearchElementButtonOn->Visible = false;

		SearchElementBox->Visible = false;
		SearchElementTextBox->Visible = false;
		SearchElementDoneButton->Visible = false;
		SearchElementDoneTextBox->Visible = false;
	}

	private: System::Void SearchElementDoneButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		SearchElementDoneButton->Visible = false;
		SearchElementDoneButtonOn->Visible = true;

		std::vector<int> vector;
		Int16 element;
		vector.clear();
		switch (mode) {
		case 0:
			if (SearchElementTextBox->Text != "" && SearchElementTextBox->Text != " " && SearchElementTextBox->Text != "  " && SearchElementTextBox->Text != "   ") {
				TreesVisualization::binaryTree.search(Int32::Parse(SearchElementTextBox->Text), vector);

				Update();
				if (*vector.data() != 0) {
					SearchElementDoneTextBox->Text = L"Высота: " + *vector.data() + "    Индекс: ";
					vector.erase(vector.begin());
					SearchElementDoneTextBox->Text += *vector.data();
				}
				else {
					SearchElementDoneTextBox->Text = L"Элемент не найден!";
				}
				SearchElementTextBox->Text = "";
			}
			break;
		case 1:
			if (SearchElementTextBox->Text != "" && SearchElementTextBox->Text != " " && SearchElementTextBox->Text != "  " && SearchElementTextBox->Text != "   ") {
				TreesVisualization::avlTree.search(Int32::Parse(SearchElementTextBox->Text), vector);
				Update();

				if (*vector.data() != 0) {
					SearchElementDoneTextBox->Text = L"Высота: " + *vector.data() + "    Индекс: ";
					vector.erase(vector.begin());
					SearchElementDoneTextBox->Text += *vector.data();
				}
				else {
					SearchElementDoneTextBox->Text = L"Элемент не найден!";
				}

				SearchElementTextBox->Text = "";
			}
			break;
		}
		//Update();
	}
	private: System::Void SearchElementDoneButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		SearchElementDoneButton->Visible = true;
		SearchElementDoneButtonOn->Visible = false;
	}





	//--------------------------------------[ Delete element ]--------------------------------------
	private: System::Void DeleteElementButton_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateTreeButton->Visible = true;
		CreateTreeButtonOn->Visible = false;
		InsertElementButton->Visible = true;
		InsertElementButtonOn->Visible = false;
		SearchElementButton->Visible = true;
		SearchElementButtonOn->Visible = false;
		DeleteElementButton->Visible = false;
		DeleteElementButtonOn->Visible = true;
		IterativeTreeButton->Visible = true;
		IterativeTreeButtonOn->Visible = false;

		CreateEmptyTreeButton->Visible = false;
		CreateBinaryTreeButton->Visible = false;
		CreateAVLTreeButton->Visible = false;

		InsertElementBox->Visible = false;
		InsertElementTextBox->Visible = false;
		InsertElementDoneButton->Visible = false;

		SearchElementBox->Visible = false;
		SearchElementTextBox->Visible = false;
		SearchElementDoneButton->Visible = false;
		SearchElementDoneTextBox->Visible = false;

		DeleteElementTextBox->Visible = true;
		DeleteElementBox->Visible = true;
		DeleteElementDoneButton->Visible = true;

		PreIterativeTreeDoneButton->Visible = false;
		InIterativeTreeDoneButton->Visible = false;
		PostIterativeTreeDoneButton->Visible = false;
		PreIterativeTreeDoneButtonOn->Visible = false;
		InIterativeTreeDoneButtonOn->Visible = false;
		PostIterativeTreeDoneButtonOn->Visible = false;
	}
	private: System::Void DeleteElementButtonOn_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteElementButton->Visible = true;
		DeleteElementButtonOn->Visible = false;

		DeleteElementBox->Visible = false;
		DeleteElementTextBox->Visible = false;
		DeleteElementDoneButton->Visible = false;
	}

	private: System::Void DeleteElementDoneButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		DeleteElementDoneButton->Visible = false;
		DeleteElementDoneButtonOn->Visible = true;
		switch (mode) {
		case 0:
			if (CountObjText->Text != "0" && DeleteElementTextBox->Text != "" && DeleteElementTextBox->Text != " " && DeleteElementTextBox->Text != "  " && DeleteElementTextBox->Text != "   ") {
				TreesVisualization::binaryTree.remove(Int32::Parse(DeleteElementTextBox->Text));
				Update();
				DeleteElementTextBox->Text = "";
			}
			break;
		case 1:
			if (CountObjText->Text != "0" && DeleteElementTextBox->Text != "" && DeleteElementTextBox->Text != " " && DeleteElementTextBox->Text != "  " && DeleteElementTextBox->Text != "   ") {
				TreesVisualization::avlTree.AVLTree::remove(Int32::Parse(DeleteElementTextBox->Text));
				Update();
				DeleteElementTextBox->Text = "";
			}
			break;
		}
	}
	private: System::Void DeleteElementDoneButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		DeleteElementDoneButton->Visible = true;
		DeleteElementDoneButtonOn->Visible = false;
	}





	//--------------------------------------[ Iterative tree ]--------------------------------------
	private: System::Void IterativeTreeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateTreeButton->Visible = true;
		CreateTreeButtonOn->Visible = false;
		InsertElementButton->Visible = true;
		InsertElementButtonOn->Visible = false;
		SearchElementButton->Visible = true;
		SearchElementButtonOn->Visible = false;
		DeleteElementButton->Visible = true;
		DeleteElementButtonOn->Visible = false;
		IterativeTreeButton->Visible = false;
		IterativeTreeButtonOn->Visible = true;

		CreateEmptyTreeButton->Visible = false;
		CreateBinaryTreeButton->Visible = false;
		CreateAVLTreeButton->Visible = false;

		InsertElementBox->Visible = false;
		InsertElementTextBox->Visible = false;
		InsertElementDoneButton->Visible = false;

		SearchElementBox->Visible = false;
		SearchElementTextBox->Visible = false;
		SearchElementDoneButton->Visible = false;
		SearchElementDoneTextBox->Visible = false;

		DeleteElementBox->Visible = false;
		DeleteElementTextBox->Visible = false;
		DeleteElementDoneButton->Visible = false;

		switch (iterativeMode) {
		case 0: 
			PreIterativeTreeDoneButton->Visible = false;
			PreIterativeTreeDoneButtonOn->Visible = true;
			InIterativeTreeDoneButton->Visible = true;
			InIterativeTreeDoneButtonOn->Visible = false;
			PostIterativeTreeDoneButton->Visible = true;
			PostIterativeTreeDoneButtonOn->Visible = false;
			break;
		case 1:
			PreIterativeTreeDoneButton->Visible = true;
			PreIterativeTreeDoneButtonOn->Visible = false;
			InIterativeTreeDoneButton->Visible = false;
			InIterativeTreeDoneButtonOn->Visible = true;
			PostIterativeTreeDoneButton->Visible = true;
			PostIterativeTreeDoneButtonOn->Visible = false;
			break;
		case 2:
			PreIterativeTreeDoneButton->Visible = true;
			PreIterativeTreeDoneButtonOn->Visible = false;
			InIterativeTreeDoneButton->Visible = true;
			InIterativeTreeDoneButtonOn->Visible = false;
			PostIterativeTreeDoneButton->Visible = false;
			PostIterativeTreeDoneButtonOn->Visible = true;
			break;
		}
	}
	private: System::Void IterativeTreeButtonOn_Click(System::Object^ sender, System::EventArgs^ e) {
		IterativeTreeButton->Visible = true;
		IterativeTreeButtonOn->Visible = false;

		PreIterativeTreeDoneButton->Visible = false;
		InIterativeTreeDoneButton->Visible = false;
		PostIterativeTreeDoneButton->Visible = false;
		PreIterativeTreeDoneButtonOn->Visible = false;
		InIterativeTreeDoneButtonOn->Visible = false;
		PostIterativeTreeDoneButtonOn->Visible = false;
	}

	private: System::Void PreIterativeTreeDoneButton_Click(System::Object^ sender, System::EventArgs^ e) {
		PreIterativeTreeDoneButton->Visible = false;
		PreIterativeTreeDoneButtonOn->Visible = true;
		InIterativeTreeDoneButton->Visible = true;
		InIterativeTreeDoneButtonOn->Visible = false;
		PostIterativeTreeDoneButton->Visible = true;
		PostIterativeTreeDoneButtonOn->Visible = false;

		iterativeMode = 0;
		Update();
	}
	private: System::Void InIterativeTreeDoneButton_Click(System::Object^ sender, System::EventArgs^ e) {
		PreIterativeTreeDoneButton->Visible = true;
		PreIterativeTreeDoneButtonOn->Visible = false;
		InIterativeTreeDoneButton->Visible = false;
		InIterativeTreeDoneButtonOn->Visible = true;
		PostIterativeTreeDoneButton->Visible = true;
		PostIterativeTreeDoneButtonOn->Visible = false;

		iterativeMode = 1;
		Update();
	}
	private: System::Void PostIterativeTreeDoneButton_Click(System::Object^ sender, System::EventArgs^ e) {
		PreIterativeTreeDoneButton->Visible = true;
		PreIterativeTreeDoneButtonOn->Visible = false;
		InIterativeTreeDoneButton->Visible = true;
		InIterativeTreeDoneButtonOn->Visible = false;
		PostIterativeTreeDoneButton->Visible = false;
		PostIterativeTreeDoneButtonOn->Visible = true;

		iterativeMode = 2;
		Update();
	}
};
}
