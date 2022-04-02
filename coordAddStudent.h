#pragma once
#include <mysql.h>
#include <string>
#include <cctype>
#include <cstring>
#include <iostream>

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Runtime::InteropServices;


	/// <summary>
	/// Summary for cordAddStudent
	/// </summary>
	public ref class cordAddStudent : public System::Windows::Forms::Form
	{
		MYSQL* con;
		MYSQL_RES* res;
	private: System::Windows::Forms::Button^ addstudentButton;
	private: System::Windows::Forms::Label^ passportError;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ countryBox;


	private: System::Windows::Forms::Label^ label4;
		   MYSQL_ROW row;
	public:
		cordAddStudent(string facultyNamePara)
		{
			con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);


			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			string query = "select dept_name from department where faculty like \"%" + facultyNamePara + "%\";";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				res = mysql_store_result(con);
				int count = mysql_num_rows(res);
				if (count > 0) {
					while ((row = mysql_fetch_row(res)) != NULL) {
						departmentBox->Items->Add(gcnew String(row[0]));
					}

				}
			}
			mysql_free_result(res);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~cordAddStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ firstNameBox;
	private: System::Windows::Forms::Label^ firstNameError;
	protected:


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lastNameError;

	private: System::Windows::Forms::TextBox^ lastNameBox;

	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ emailError;

	private: System::Windows::Forms::TextBox^ emailBox;

	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::TextBox^ phoneBox;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ passportBox;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::DateTimePicker^ DOB;
	private: System::Windows::Forms::Label^ countryError;
	private: System::Windows::Forms::TextBox^ ResCountryBox;




	private: System::Windows::Forms::Label^ label15;

	private: System::Windows::Forms::TextBox^ cityBox;

	private: System::Windows::Forms::Label^ label16;

	private: System::Windows::Forms::TextBox^ streetBox;

	private: System::Windows::Forms::Label^ label18;

	private: System::Windows::Forms::TextBox^ addressBox;

	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::ComboBox^ departmentBox;


	private: System::Windows::Forms::Label^ label22;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->firstNameBox = (gcnew System::Windows::Forms::TextBox());
			this->firstNameError = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lastNameError = (gcnew System::Windows::Forms::Label());
			this->lastNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->emailError = (gcnew System::Windows::Forms::Label());
			this->emailBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->phoneBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->passportBox = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->DOB = (gcnew System::Windows::Forms::DateTimePicker());
			this->countryError = (gcnew System::Windows::Forms::Label());
			this->ResCountryBox = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->cityBox = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->streetBox = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->addressBox = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->departmentBox = (gcnew System::Windows::Forms::ComboBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->addstudentButton = (gcnew System::Windows::Forms::Button());
			this->passportError = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->countryBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(69, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"firstname*";
			// 
			// firstNameBox
			// 
			this->firstNameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->firstNameBox->Location = System::Drawing::Point(126, 75);
			this->firstNameBox->Name = L"firstNameBox";
			this->firstNameBox->Size = System::Drawing::Size(256, 20);
			this->firstNameBox->TabIndex = 1;
			// 
			// firstNameError
			// 
			this->firstNameError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->firstNameError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->firstNameError->Location = System::Drawing::Point(389, 77);
			this->firstNameError->Name = L"firstNameError";
			this->firstNameError->Size = System::Drawing::Size(119, 18);
			this->firstNameError->TabIndex = 2;
			this->firstNameError->Text = L"        ";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(171, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(158, 15);
			this->label3->TabIndex = 3;
			this->label3->Text = L"all labels with (*) must be filled";
			// 
			// lastNameError
			// 
			this->lastNameError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lastNameError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastNameError->Location = System::Drawing::Point(389, 103);
			this->lastNameError->Name = L"lastNameError";
			this->lastNameError->Size = System::Drawing::Size(119, 18);
			this->lastNameError->TabIndex = 6;
			this->lastNameError->Text = L"      ";
			// 
			// lastNameBox
			// 
			this->lastNameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lastNameBox->Location = System::Drawing::Point(127, 101);
			this->lastNameBox->Name = L"lastNameBox";
			this->lastNameBox->Size = System::Drawing::Size(256, 20);
			this->lastNameBox->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(69, 103);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 15);
			this->label5->TabIndex = 4;
			this->label5->Text = L"lastname*";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(59, 129);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(68, 15);
			this->label7->TabIndex = 7;
			this->label7->Text = L"department*";
			// 
			// emailError
			// 
			this->emailError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailError->Location = System::Drawing::Point(389, 155);
			this->emailError->Name = L"emailError";
			this->emailError->Size = System::Drawing::Size(119, 18);
			this->emailError->TabIndex = 12;
			this->emailError->Text = L"      ";
			// 
			// emailBox
			// 
			this->emailBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailBox->Location = System::Drawing::Point(127, 153);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(256, 20);
			this->emailBox->TabIndex = 11;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(86, 155);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(38, 15);
			this->label9->TabIndex = 10;
			this->label9->Text = L"email*";
			// 
			// phoneBox
			// 
			this->phoneBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phoneBox->Location = System::Drawing::Point(127, 179);
			this->phoneBox->Name = L"phoneBox";
			this->phoneBox->Size = System::Drawing::Size(256, 20);
			this->phoneBox->TabIndex = 14;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(42, 184);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(79, 15);
			this->label11->TabIndex = 13;
			this->label11->Text = L"phone Number";
			// 
			// passportBox
			// 
			this->passportBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passportBox->Location = System::Drawing::Point(127, 205);
			this->passportBox->Name = L"passportBox";
			this->passportBox->Size = System::Drawing::Size(256, 20);
			this->passportBox->TabIndex = 17;
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(32, 210);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(95, 15);
			this->label13->TabIndex = 16;
			this->label13->Text = L"passport number*";
			// 
			// DOB
			// 
			this->DOB->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DOB->Location = System::Drawing::Point(127, 286);
			this->DOB->Name = L"DOB";
			this->DOB->Size = System::Drawing::Size(205, 20);
			this->DOB->TabIndex = 25;
			// 
			// countryError
			// 
			this->countryError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->countryError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->countryError->Location = System::Drawing::Point(389, 314);
			this->countryError->Name = L"countryError";
			this->countryError->Size = System::Drawing::Size(119, 18);
			this->countryError->TabIndex = 28;
			this->countryError->Text = L"   ";
			// 
			// ResCountryBox
			// 
			this->ResCountryBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ResCountryBox->Location = System::Drawing::Point(127, 312);
			this->ResCountryBox->Name = L"ResCountryBox";
			this->ResCountryBox->Size = System::Drawing::Size(256, 20);
			this->ResCountryBox->TabIndex = 27;
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(24, 314);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(103, 15);
			this->label15->TabIndex = 26;
			this->label15->Text = L"resisdence country*";
			// 
			// cityBox
			// 
			this->cityBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cityBox->Location = System::Drawing::Point(127, 338);
			this->cityBox->Name = L"cityBox";
			this->cityBox->Size = System::Drawing::Size(256, 20);
			this->cityBox->TabIndex = 30;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(69, 340);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(26, 15);
			this->label16->TabIndex = 29;
			this->label16->Text = L"city";
			// 
			// streetBox
			// 
			this->streetBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->streetBox->Location = System::Drawing::Point(127, 364);
			this->streetBox->Name = L"streetBox";
			this->streetBox->Size = System::Drawing::Size(256, 20);
			this->streetBox->TabIndex = 33;
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(69, 366);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(34, 15);
			this->label18->TabIndex = 32;
			this->label18->Text = L"street";
			// 
			// addressBox
			// 
			this->addressBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addressBox->Location = System::Drawing::Point(127, 390);
			this->addressBox->Name = L"addressBox";
			this->addressBox->Size = System::Drawing::Size(256, 20);
			this->addressBox->TabIndex = 36;
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(69, 392);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(43, 15);
			this->label20->TabIndex = 35;
			this->label20->Text = L"address";
			// 
			// departmentBox
			// 
			this->departmentBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->departmentBox->FormattingEnabled = true;
			this->departmentBox->Location = System::Drawing::Point(127, 129);
			this->departmentBox->Name = L"departmentBox";
			this->departmentBox->Size = System::Drawing::Size(256, 21);
			this->departmentBox->TabIndex = 39;
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(124, 264);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(128, 15);
			this->label22->TabIndex = 40;
			this->label22->Text = L"choose your date of birth";
			// 
			// addstudentButton
			// 
			this->addstudentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addstudentButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addstudentButton->Location = System::Drawing::Point(80, 416);
			this->addstudentButton->Name = L"addstudentButton";
			this->addstudentButton->Size = System::Drawing::Size(343, 40);
			this->addstudentButton->TabIndex = 41;
			this->addstudentButton->Text = L"Add student";
			this->addstudentButton->UseVisualStyleBackColor = true;
			this->addstudentButton->Click += gcnew System::EventHandler(this, &cordAddStudent::addstudentButton_Click);
			// 
			// passportError
			// 
			this->passportError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passportError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passportError->Location = System::Drawing::Point(389, 205);
			this->passportError->Name = L"passportError";
			this->passportError->Size = System::Drawing::Size(119, 18);
			this->passportError->TabIndex = 42;
			this->passportError->Text = L"      ";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(388, 231);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 18);
			this->label2->TabIndex = 45;
			this->label2->Text = L"      ";
			// 
			// countryBox
			// 
			this->countryBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->countryBox->Location = System::Drawing::Point(126, 231);
			this->countryBox->Name = L"countryBox";
			this->countryBox->Size = System::Drawing::Size(256, 20);
			this->countryBox->TabIndex = 44;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(73, 236);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 15);
			this->label4->TabIndex = 43;
			this->label4->Text = L"country*";
			// 
			// cordAddStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(606, 481);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->countryBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->passportError);
			this->Controls->Add(this->addstudentButton);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->departmentBox);
			this->Controls->Add(this->addressBox);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->streetBox);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->cityBox);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->countryError);
			this->Controls->Add(this->ResCountryBox);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->DOB);
			this->Controls->Add(this->passportBox);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->phoneBox);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->emailError);
			this->Controls->Add(this->emailBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->lastNameError);
			this->Controls->Add(this->lastNameBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->firstNameError);
			this->Controls->Add(this->firstNameBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"cordAddStudent";
			this->Text = L"Add Student";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addstudentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string firstName((char*)(Marshal::StringToHGlobalAnsi(firstNameBox->Text)).ToPointer());
		string lastName((char*)(Marshal::StringToHGlobalAnsi(lastNameBox->Text)).ToPointer());
		string department((char*)(Marshal::StringToHGlobalAnsi(departmentBox->Text)).ToPointer());
		string email((char*)(Marshal::StringToHGlobalAnsi(emailBox->Text)).ToPointer());
		string phone((char*)(Marshal::StringToHGlobalAnsi(phoneBox->Text)).ToPointer());
		string passport((char*)(Marshal::StringToHGlobalAnsi(passportBox->Text)).ToPointer());
		string country((char*)(Marshal::StringToHGlobalAnsi(countryBox->Text)).ToPointer());
		string city((char*)(Marshal::StringToHGlobalAnsi(cityBox->Text)).ToPointer());
		string street((char*)(Marshal::StringToHGlobalAnsi(streetBox->Text)).ToPointer());
		string address((char*)(Marshal::StringToHGlobalAnsi(addressBox->Text)).ToPointer());
		string resCountry((char*)(Marshal::StringToHGlobalAnsi(ResCountryBox->Text)).ToPointer());
		int yearInt = DOB->Value.Year;
		int monthInt = DOB->Value.Month;
		int dayInt = DOB->Value.Day;
		string day = to_string(dayInt);
		string year = to_string(yearInt);
		string month;
		switch (monthInt) {
		case 1:
			month = "January";
			break;
		case 2:
			month = "Febuary";
			break;
		case 3:
			month = "Match";
			break;
		case 4:
			month = "April";
			break;
		case 5:
			month = "May";
			break;
		case 6:
			month = "June";
			break;
		case 7:
			month = "July";
			break;
		case 8:
			month = "August";
			break;
		case 9:
			month = "Semptember";
			break;
		case 10:
			month = "October";
			break;
		case 11:
			month = "November";
			break;
		case 12:
			month = "December";
			break;
		}
		

		if (firstName == "") {
			firstNameError->Text = "!!!";
		}
		if (lastName == "") {
			lastNameError->Text = "!!!";
		}
		if (email == "") {
			emailError->Text = "!!!";
		}
		if (passport == "") {
			passportError->Text = "!!!";
		}
		if (country == "") {
			countryError->Text = "!!!";
		}
		if (phone == "") {
			phone = "0";
		}

		if (firstName != "" && lastName != "" && email != "" && passport != "" && country != "") {
			string query = "INSERT INTO `logo_university`.`student` (`first_name`, `last_name`, `dept_name`, `email`, `passport_number`, `phone_number`, `password`, `yob`, `mob`, `dob`, `country`, `country_of_res`, `city`, `street`, `address`)"
				"VALUES(\"" + firstName + "\",\"" + lastName + "\",\"" + department + "\",\"" + email + "\",\"" + passport + "\"," + phone + ",\"" + passport + "\"," + year + ",\"" + month + "\"," + day + ",\"" + country + "\",\"" + resCountry + "\",\"" + city + "\",\"" + street + "\", \"" + address + "\");";

			int check = mysql_query(con, query.c_str());
			cout << query << endl;
			if (!check) {
				this->Close();
			}
		}
	}
};
}
