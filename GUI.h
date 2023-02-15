#pragma once
#include "Nacitavanie.h"
#include "structures/table/table.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/table/unsorted_sequence_table.h"
#include "Filter.h"
#include "FilterPodlaHodnoty.h"
#include "FilterPodlaIntervalu.h"
#include "UniverzalnyFilter.h"
#include "ZlozenyFilter.h"
#include "Filtrovac.h"
#include "Kriterium.h"
#include "KriteriumUJ.h"
#include "Typ.h"
#include "structures/table/sorting/quick_sort.h"
#include <msclr/marshal_cppstd.h>
#include "structures/heap_monitor.h"

namespace BalaziMatusAUS2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			aNacitavac = new Nacitavanie();
			aZlozenyFilter = new ZlozenyFilter<UzemnaJednotka*>();
			
			aTabulka = nullptr;
			aCistaTabulka = new structures::SortedSequenceTable<std::string, UzemnaJednotka*>();
			aZoradenaTabulka = new structures::UnsortedSequenceTable<std::string, UzemnaJednotka*>();

			aKriteriumNazov = new KriteriumUJNazov();
			aFilterNazov = nullptr;
			aKriteriumTyp = new KriteriumUJTyp();
			aFilterTyp = nullptr;
			aVyssiUzemCelok = nullptr;
			aKriteriumPrislusnost = new KriteriumUJPrislusnost(aVyssiUzemCelok);
			aFilterPrislusnost = nullptr;
			aKriteriumPocetObyvatelov = new KriteriumUJPocetObyvatelov();
			aFilterPocetObyvatelov = nullptr;
			aKriteriumZastavanost = new KriteriumUJZastavanost();
			aFilterZastavanost = nullptr;

			aOd = 0;
			aDo = 0;
			aVzostupne = true;
			aKritCelok = false;
			aPodlaNazvu = false;

			aFiltrovac = new Filtrovac<std::string, UzemnaJednotka*>();

			aTriedenieNazov = new structures::QuickSort<std::string, UzemnaJednotka*, std::string>();
			aTriedeniePocetObyv = new structures::QuickSort<std::string, UzemnaJednotka*, int>();
			aTriedenieZastavanost = new structures::QuickSort<std::string, UzemnaJednotka*, double>();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
			delete aNacitavac;
			aNacitavac = nullptr;

			delete aZlozenyFilter;
			aZlozenyFilter = nullptr;

			delete aFiltrovac;
			aFiltrovac = nullptr;

			delete aCistaTabulka;
			aCistaTabulka = nullptr;
			delete aZoradenaTabulka;
			aZoradenaTabulka = nullptr;

			delete aKriteriumNazov;
			aKriteriumNazov = nullptr;
			delete aKriteriumTyp;
			aKriteriumTyp = nullptr;
			delete aKriteriumPrislusnost;
			aKriteriumPrislusnost = nullptr;
			delete aKriteriumPocetObyvatelov;
			aKriteriumPocetObyvatelov = nullptr;
			delete aKriteriumZastavanost;
			aKriteriumZastavanost = nullptr;

			delete aTriedenieNazov;
			aTriedenieNazov = nullptr;
			delete aTriedeniePocetObyv;
			aTriedeniePocetObyv = nullptr;
			delete aTriedenieZastavanost;
			aTriedenieZastavanost = nullptr;
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:










	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ mENUToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ nacitajDataToolStripMenuItem;

	private:
		Nacitavanie* aNacitavac;
		ZlozenyFilter<UzemnaJednotka*>* aZlozenyFilter;

		structures::SortedSequenceTable<std::string, UzemnaJednotka*>* aTabulka;
		structures::SortedSequenceTable<std::string, UzemnaJednotka*>* aCistaTabulka;
		structures::UnsortedSequenceTable<std::string, UzemnaJednotka*>* aZoradenaTabulka;

		double aOd;
		double aDo;
		bool aVzostupne;
		bool aKritCelok;
		bool aPodlaNazvu;

		System::String^ aNazovUzemnejJednotky;

		UzemnaJednotka* aVyssiUzemCelok;

		Typ aTyp;

		KriteriumUJNazov* aKriteriumNazov;
		KriteriumUJTyp* aKriteriumTyp;
		KriteriumUJPrislusnost* aKriteriumPrislusnost;
		KriteriumUJPocetObyvatelov* aKriteriumPocetObyvatelov;
		KriteriumUJZastavanost* aKriteriumZastavanost;

		FilterUJNazov* aFilterNazov;
		FilterUJTyp* aFilterTyp;
		FilterUJPrislusnost* aFilterPrislusnost;
		FilterUJPocetObyvatelov* aFilterPocetObyvatelov;
		FilterUJZastavanost* aFilterZastavanost;
		
		Filtrovac<std::string, UzemnaJednotka*>* aFiltrovac;

		structures::QuickSort<std::string, UzemnaJednotka*, std::string>* aTriedenieNazov;
		structures::QuickSort<std::string, UzemnaJednotka*, int>* aTriedeniePocetObyv;
		structures::QuickSort<std::string, UzemnaJednotka*, double>* aTriedenieZastavanost;












	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::RadioButton^ radioButton1;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::RadioButton^ radioButton3;
private: System::Windows::Forms::RadioButton^ radioButton2;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::RichTextBox^ richTextBox1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_nazov;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_okres;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_kraj;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_stat;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_predprod;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_prod;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_poprod;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_obyv;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_vymera;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_plocha;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_zastavanost;



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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mENUToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nacitajDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->col_nazov = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_okres = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_kraj = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_stat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_predprod = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_prod = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_poprod = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_obyv = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_vymera = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_plocha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_zastavanost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->col_nazov,
					this->col_okres, this->col_kraj, this->col_stat, this->col_predprod, this->col_prod, this->col_poprod, this->col_obyv, this->col_vymera,
					this->col_plocha, this->col_zastavanost
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 135);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->Size = System::Drawing::Size(1180, 353);
			this->dataGridView1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->mENUToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1204, 25);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mENUToolStripMenuItem
			// 
			this->mENUToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->nacitajDataToolStripMenuItem });
			this->mENUToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->mENUToolStripMenuItem->Name = L"mENUToolStripMenuItem";
			this->mENUToolStripMenuItem->Size = System::Drawing::Size(58, 21);
			this->mENUToolStripMenuItem->Text = L"MENU";
			// 
			// nacitajDataToolStripMenuItem
			// 
			this->nacitajDataToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->nacitajDataToolStripMenuItem->Name = L"nacitajDataToolStripMenuItem";
			this->nacitajDataToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->nacitajDataToolStripMenuItem->Text = L"Nacitaj data";
			this->nacitajDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::nacitajDataToolStripMenuItem_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"", L"OBEC", L"OKRES", L"KRAJ", L"STAT" });
			this->comboBox1->Location = System::Drawing::Point(133, 52);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(130, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"FilterUJTyp";
			this->label1->Click += gcnew System::EventHandler(this, &GUI::label1_Click);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(1033, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 36);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Vyfiltruj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &GUI::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"FilterUJNazov";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 79);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Potvrd nazov";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GUI::button2_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Vzostupne", L"Zostupne" });
			this->comboBox2->Location = System::Drawing::Point(30, 64);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 8;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Zoradenie";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(30, 90);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Zorad";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GUI::button3_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 36);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(56, 17);
			this->radioButton1->TabIndex = 11;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Nazov";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &GUI::radioButton1_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Location = System::Drawing::Point(157, 11);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(149, 114);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zoradenie podla kriteria";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 82);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(84, 17);
			this->radioButton3->TabIndex = 14;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Zastavanost";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &GUI::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 59);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(108, 17);
			this->radioButton2->TabIndex = 13;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Pocet obyvatelov";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &GUI::radioButton2_CheckedChanged);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(1033, 53);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 36);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Vypni filtre";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GUI::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(260, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(121, 20);
			this->textBox2->TabIndex = 14;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &GUI::textBox2_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(257, 37);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"FilterUJPrislusnost";
			this->label4->Click += gcnew System::EventHandler(this, &GUI::label4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(260, 79);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(121, 23);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Potvrd prislusnost";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &GUI::button5_Click);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"FilterUJPocetObyvatelov", L"FilterUJZastavanost" });
			this->comboBox3->Location = System::Drawing::Point(6, 52);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 17;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::comboBox3_SelectedIndexChanged);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Enabled = false;
			this->numericUpDown1->Location = System::Drawing::Point(144, 53);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1410065408, 2, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(60, 20);
			this->numericUpDown1->TabIndex = 18;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &GUI::numericUpDown1_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(141, 39);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Od";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(207, 38);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Do";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Enabled = false;
			this->numericUpDown2->Location = System::Drawing::Point(210, 53);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1410065408, 2, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(60, 20);
			this->numericUpDown2->TabIndex = 21;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &GUI::numericUpDown2_ValueChanged);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(6, 79);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(121, 23);
			this->button6->TabIndex = 22;
			this->button6->Text = L"Potvrd interval";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &GUI::button6_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Location = System::Drawing::Point(312, 11);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(393, 114);
			this->groupBox2->TabIndex = 23;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"FilterPodlaHodnoty";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &GUI::groupBox2_Enter);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->comboBox3);
			this->groupBox3->Controls->Add(this->numericUpDown1);
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Controls->Add(this->numericUpDown2);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Location = System::Drawing::Point(711, 11);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(279, 114);
			this->groupBox3->TabIndex = 24;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"FilterPodlaIntervalu";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(996, 95);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(196, 34);
			this->richTextBox1->TabIndex = 25;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &GUI::richTextBox1_TextChanged);
			// 
			// col_nazov
			// 
			this->col_nazov->HeaderText = L"Nazov";
			this->col_nazov->Name = L"col_nazov";
			// 
			// col_okres
			// 
			this->col_okres->HeaderText = L"Okres";
			this->col_okres->Name = L"col_okres";
			// 
			// col_kraj
			// 
			this->col_kraj->HeaderText = L"Kraj";
			this->col_kraj->Name = L"col_kraj";
			// 
			// col_stat
			// 
			this->col_stat->HeaderText = L"Stat";
			this->col_stat->Name = L"col_stat";
			// 
			// col_predprod
			// 
			this->col_predprod->HeaderText = L"Predprod. obyv.";
			this->col_predprod->Name = L"col_predprod";
			this->col_predprod->Width = 110;
			// 
			// col_prod
			// 
			this->col_prod->HeaderText = L"Prod. obyv.";
			this->col_prod->Name = L"col_prod";
			// 
			// col_poprod
			// 
			this->col_poprod->HeaderText = L"Poprod. obyv.";
			this->col_poprod->Name = L"col_poprod";
			// 
			// col_obyv
			// 
			this->col_obyv->HeaderText = L"Pocet obyv.";
			this->col_obyv->Name = L"col_obyv";
			// 
			// col_vymera
			// 
			this->col_vymera->HeaderText = L"Vymera";
			this->col_vymera->Name = L"col_vymera";
			// 
			// col_plocha
			// 
			this->col_plocha->HeaderText = L"Zastav. plocha";
			this->col_plocha->Name = L"col_plocha";
			this->col_plocha->Width = 110;
			// 
			// col_zastavanost
			// 
			this->col_zastavanost->HeaderText = L"Zastavanost";
			this->col_zastavanost->Name = L"col_zastavanost";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1204, 500);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"GUI";
			this->Text = L"GUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void nacitajDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nacitajUdajeDoDataGrid(structures::Table<std::string, UzemnaJednotka*>* pTabulka);
	private: System::Void vypisInfo(Color clr, String^ text);
 private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
