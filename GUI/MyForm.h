#pragma once
#include "Conistency.h"
#include"ConvertString.h"
#include "Compression.h"
#include "XMLtoJSON.h"

namespace MyProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	using namespace std;


	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(257, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 22);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(65, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(149, 18);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Please open a text file.";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(371, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Your file\'s data will be shown here!";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(272, 108);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(407, 144);
			this->textBox1->TabIndex = 5;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 108);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 28);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Check Consistency";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(271, 287);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(407, 135);
			this->textBox2->TabIndex = 7;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button3->Location = System::Drawing::Point(15, 182);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 26);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Compression";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button4->Location = System::Drawing::Point(153, 182);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(108, 28);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Decompression";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(80, 143);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(118, 30);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Convert to Json";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(153, 108);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(108, 29);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Correct";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(12, 341);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(204, 18);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Any change will be shown here!";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button7->Location = System::Drawing::Point(80, 216);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(118, 25);
			this->button7->TabIndex = 13;
			this->button7->Text = L"Format";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(102, 257);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 14;
			this->button8->Text = L"Visualize";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(699, 438);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	String^ ReadFileIn;

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox2->Text = "";
		String^ File;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			File = openFileDialog1->FileName;
		}

		StreamReader^ input_file = File::OpenText(File);
		ReadFileIn = File::ReadAllText(File);
		textBox1->Text = ReadFileIn;

		StreamWriter^ output_file = File::CreateText("test.txt");

		String^ line;
		line = input_file->ReadToEnd();
		MessageBox::Show(line);
		output_file->WriteLine(line);

		if (input_file)
		{
			input_file->Close();
			output_file->Close();
		}

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {	
}



private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {	
	//textBox2->Text = "";
	//Text in the file --> String^
	output = "";
	ReadFileIn = textBox1->Text;
	//String^ --> string
	
	string Readstd;
	MarshalString(ReadFileIn, Readstd);
	
	//Checking Consistency
	checkConsistency(Readstd);
	String^ Output = gcnew String(output.c_str());
	textBox2->Text = Output;
}

private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	
	//Text in the file --> String^
	ReadFileIn = textBox1->Text;
	//String^ --> string
	string Readstd;
	MarshalString(ReadFileIn, Readstd);

	//Compression
	String^ Huff = HuffmanTreeF(Readstd);
	textBox2->Text = Huff;

	StreamWriter^ Compressed = gcnew StreamWriter("Compressed.txt");
	Compressed->WriteLine(Huff);
	Compressed->Close();

}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//Decompression
	String^ Decompressed = Decompression();
	textBox2->Text = Decompressed;
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	//Text in the file --> String^
	ReadFileIn = textBox1->Text;
	//String^ --> string
	string Readstd;
	MarshalString(ReadFileIn, Readstd);

	//Convert to JSON
	string removed = RemoveSpaces(Readstd);
	textBox2->Text = toJson(removed);

	//Creaing a JSON text file
	StreamWriter^ JSON_file = gcnew StreamWriter("JSON.txt");
	JSON_file->WriteLine(toJson(removed));
	JSON_file->Close();

	MessageBox::Show(toJson(removed));

}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	//Text in the file --> String^
	textBox2->Text = "";
	ReadFileIn = textBox1->Text;
	//String^ --> string
	string Readstd;
	MarshalString(ReadFileIn, Readstd);

	//Checking Consistency
	string CorrectedXml = checkConsistency(Readstd);

	//Correction 
	String^ Corrected = correct(CorrectedXml);
	textBox1->Text = Corrected;

	StreamWriter^ Corrected_Text = gcnew StreamWriter("Corrected.txt");
	Corrected_Text->WriteLine(Corrected);
	Corrected_Text->Close();
}

private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	//Text in the file --> String^
	textBox2->Text = "";
	Lists = "";
	ReadFileIn = textBox1->Text;
	//String^ --> string
	string Readstd;
	MarshalString(ReadFileIn, Readstd);

	//Format
	textBox1->Text = format(Readstd);

	StreamWriter^ formatted_file = gcnew StreamWriter("test.txt");
	formatted_file->WriteLine(format(Readstd));
	formatted_file->Close();

	MessageBox::Show(format(Readstd));
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

	//Final List
	Lists = "";
	string L;
	L = Finaal();
	String^ List = gcnew String(L.c_str());
	String^ OUT = gcnew String(test().c_str());
	textBox2->Text = OUT;


	//Creaing a dot file
	StreamWriter^ out_file = gcnew StreamWriter("graph.dot");
	out_file->WriteLine(List);
	out_file->Close();

}
};
}


