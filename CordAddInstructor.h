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
	/// Summary for CordAddInstructor
	/// </summary>
	public ref class CordAddInstructor : public System::Windows::Forms::Form
	{
		MYSQL* con;

	public:
		CordAddInstructor(string facultyNamePara)
		{
			con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			MYSQL_RES* res;
			MYSQL_ROW row;

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
		~CordAddInstructor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::TextBox^ countryBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ passportError;
	private: System::Windows::Forms::Button^ addstudentButton;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::ComboBox^ departmentBox;
	private: System::Windows::Forms::TextBox^ addressBox;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ streetBox;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ cityBox;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ countryError;
	private: System::Windows::Forms::TextBox^ ResCountryBox;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::DateTimePicker^ DOB;
	private: System::Windows::Forms::TextBox^ passportBox;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ phoneBox;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ emailError;
	private: System::Windows::Forms::TextBox^ emailBox;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ lastNameError;
	private: System::Windows::Forms::TextBox^ lastNameBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ firstNameError;
	private: System::Windows::Forms::TextBox^ firstNameBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ officeBox;
	private: System::Windows::Forms::Label^ label6;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->countryBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->passportError = (gcnew System::Windows::Forms::Label());
			this->addstudentButton = (gcnew System::Windows::Forms::Button());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->departmentBox = (gcnew System::Windows::Forms::ComboBox());
			this->addressBox = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->streetBox = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->cityBox = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->countryError = (gcnew System::Windows::Forms::Label());
			this->ResCountryBox = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->DOB = (gcnew System::Windows::Forms::DateTimePicker());
			this->passportBox = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->phoneBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->emailError = (gcnew System::Windows::Forms::Label());
			this->emailBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->lastNameError = (gcnew System::Windows::Forms::Label());
			this->lastNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->firstNameError = (gcnew System::Windows::Forms::Label());
			this->firstNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->officeBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(409, 247);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 18);
			this->label2->TabIndex = 77;
			this->label2->Text = L"      ";
			// 
			// countryBox
			// 
			this->countryBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->countryBox->Location = System::Drawing::Point(147, 247);
			this->countryBox->Name = L"countryBox";
			this->countryBox->Size = System::Drawing::Size(256, 20);
			this->countryBox->TabIndex = 76;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(94, 252);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 15);
			this->label4->TabIndex = 75;
			this->label4->Text = L"country*";
			// 
			// passportError
			// 
			this->passportError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passportError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passportError->Location = System::Drawing::Point(410, 221);
			this->passportError->Name = L"passportError";
			this->passportError->Size = System::Drawing::Size(119, 18);
			this->passportError->TabIndex = 74;
			this->passportError->Text = L"      ";
			// 
			// addstudentButton
			// 
			this->addstudentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addstudentButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addstudentButton->Location = System::Drawing::Point(101, 432);
			this->addstudentButton->Name = L"addstudentButton";
			this->addstudentButton->Size = System::Drawing::Size(302, 40);
			this->addstudentButton->TabIndex = 73;
			this->addstudentButton->Text = L"Add Instructor";
			this->addstudentButton->UseVisualStyleBackColor = true;
			this->addstudentButton->Click += gcnew System::EventHandler(this, &CordAddInstructor::addstudentButton_Click);
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(145, 280);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(128, 15);
			this->label22->TabIndex = 72;
			this->label22->Text = L"choose your date of birth";
			// 
			// departmentBox
			// 
			this->departmentBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->departmentBox->FormattingEnabled = true;
			this->departmentBox->Location = System::Drawing::Point(148, 119);
			this->departmentBox->Name = L"departmentBox";
			this->departmentBox->Size = System::Drawing::Size(256, 21);
			this->departmentBox->TabIndex = 71;
			// 
			// addressBox
			// 
			this->addressBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addressBox->Location = System::Drawing::Point(148, 406);
			this->addressBox->Name = L"addressBox";
			this->addressBox->Size = System::Drawing::Size(256, 20);
			this->addressBox->TabIndex = 70;
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(90, 408);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(43, 15);
			this->label20->TabIndex = 69;
			this->label20->Text = L"address";
			// 
			// streetBox
			// 
			this->streetBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->streetBox->Location = System::Drawing::Point(148, 380);
			this->streetBox->Name = L"streetBox";
			this->streetBox->Size = System::Drawing::Size(256, 20);
			this->streetBox->TabIndex = 68;
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(90, 382);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(34, 15);
			this->label18->TabIndex = 67;
			this->label18->Text = L"street";
			// 
			// cityBox
			// 
			this->cityBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cityBox->Location = System::Drawing::Point(148, 354);
			this->cityBox->Name = L"cityBox";
			this->cityBox->Size = System::Drawing::Size(256, 20);
			this->cityBox->TabIndex = 66;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(90, 356);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(26, 15);
			this->label16->TabIndex = 65;
			this->label16->Text = L"city";
			// 
			// countryError
			// 
			this->countryError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->countryError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->countryError->Location = System::Drawing::Point(410, 330);
			this->countryError->Name = L"countryError";
			this->countryError->Size = System::Drawing::Size(119, 18);
			this->countryError->TabIndex = 64;
			this->countryError->Text = L"   ";
			// 
			// ResCountryBox
			// 
			this->ResCountryBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ResCountryBox->Location = System::Drawing::Point(148, 328);
			this->ResCountryBox->Name = L"ResCountryBox";
			this->ResCountryBox->Size = System::Drawing::Size(256, 20);
			this->ResCountryBox->TabIndex = 63;
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(45, 330);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(103, 15);
			this->label15->TabIndex = 62;
			this->label15->Text = L"resisdence country*";
			// 
			// DOB
			// 
			this->DOB->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DOB->Location = System::Drawing::Point(148, 302);
			this->DOB->Name = L"DOB";
			this->DOB->Size = System::Drawing::Size(205, 20);
			this->DOB->TabIndex = 61;
			// 
			// passportBox
			// 
			this->passportBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passportBox->Location = System::Drawing::Point(148, 221);
			this->passportBox->Name = L"passportBox";
			this->passportBox->Size = System::Drawing::Size(256, 20);
			this->passportBox->TabIndex = 60;
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(53, 226);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(95, 15);
			this->label13->TabIndex = 59;
			this->label13->Text = L"passport number*";
			// 
			// phoneBox
			// 
			this->phoneBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phoneBox->Location = System::Drawing::Point(148, 195);
			this->phoneBox->Name = L"phoneBox";
			this->phoneBox->Size = System::Drawing::Size(256, 20);
			this->phoneBox->TabIndex = 58;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(63, 200);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(79, 15);
			this->label11->TabIndex = 57;
			this->label11->Text = L"phone Number";
			// 
			// emailError
			// 
			this->emailError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailError->Location = System::Drawing::Point(410, 145);
			this->emailError->Name = L"emailError";
			this->emailError->Size = System::Drawing::Size(119, 18);
			this->emailError->TabIndex = 56;
			this->emailError->Text = L"      ";
			// 
			// emailBox
			// 
			this->emailBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailBox->Location = System::Drawing::Point(148, 143);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(256, 20);
			this->emailBox->TabIndex = 55;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(107, 145);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(38, 15);
			this->label9->TabIndex = 54;
			this->label9->Text = L"email*";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(80, 119);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(68, 15);
			this->label7->TabIndex = 53;
			this->label7->Text = L"department*";
			// 
			// lastNameError
			// 
			this->lastNameError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lastNameError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastNameError->Location = System::Drawing::Point(410, 93);
			this->lastNameError->Name = L"lastNameError";
			this->lastNameError->Size = System::Drawing::Size(119, 18);
			this->lastNameError->TabIndex = 52;
			this->lastNameError->Text = L"      ";
			// 
			// lastNameBox
			// 
			this->lastNameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lastNameBox->Location = System::Drawing::Point(148, 91);
			this->lastNameBox->Name = L"lastNameBox";
			this->lastNameBox->Size = System::Drawing::Size(256, 20);
			this->lastNameBox->TabIndex = 51;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(90, 93);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 15);
			this->label5->TabIndex = 50;
			this->label5->Text = L"lastname*";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(192, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(158, 15);
			this->label3->TabIndex = 49;
			this->label3->Text = L"all labels with (*) must be filled";
			// 
			// firstNameError
			// 
			this->firstNameError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->firstNameError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->firstNameError->Location = System::Drawing::Point(410, 67);
			this->firstNameError->Name = L"firstNameError";
			this->firstNameError->Size = System::Drawing::Size(119, 18);
			this->firstNameError->TabIndex = 48;
			this->firstNameError->Text = L"        ";
			// 
			// firstNameBox
			// 
			this->firstNameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->firstNameBox->Location = System::Drawing::Point(148, 65);
			this->firstNameBox->Name = L"firstNameBox";
			this->firstNameBox->Size = System::Drawing::Size(256, 20);
			this->firstNameBox->TabIndex = 47;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(90, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 15);
			this->label1->TabIndex = 46;
			this->label1->Text = L"firstname*";
			// 
			// officeBox
			// 
			this->officeBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->officeBox->Location = System::Drawing::Point(147, 169);
			this->officeBox->Name = L"officeBox";
			this->officeBox->Size = System::Drawing::Size(256, 20);
			this->officeBox->TabIndex = 79;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(106, 171);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(34, 15);
			this->label6->TabIndex = 78;
			this->label6->Text = L"office";
			// 
			// CordAddInstructor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(613, 557);
			this->Controls->Add(this->officeBox);
			this->Controls->Add(this->label6);
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
			this->Name = L"CordAddInstructor";
			this->Text = L"Add Instructor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addstudentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		string firstName((char*)(Marshal::StringToHGlobalAnsi(firstNameBox->Text)).ToPointer());
		string lastName((char*)(Marshal::StringToHGlobalAnsi(lastNameBox->Text)).ToPointer());
		string department((char*)(Marshal::StringToHGlobalAnsi(departmentBox->Text)).ToPointer());
		string email((char*)(Marshal::StringToHGlobalAnsi(emailBox->Text)).ToPointer());
		string office((char*)(Marshal::StringToHGlobalAnsi(officeBox->Text)).ToPointer());
		string phone((char*)(Marshal::StringToHGlobalAnsi(phoneBox->Text)).ToPointer());
		string passport((char*)(Marshal::StringToHGlobalAnsi(passportBox->Text)).ToPointer());
		string country((char*)(Marshal::StringToHGlobalAnsi(countryBox->Text)).ToPointer());
		string resCountry((char*)(Marshal::StringToHGlobalAnsi(ResCountryBox->Text)).ToPointer());
		string city((char*)(Marshal::StringToHGlobalAnsi(cityBox->Text)).ToPointer());
		string street((char*)(Marshal::StringToHGlobalAnsi(streetBox->Text)).ToPointer());
		string address((char*)(Marshal::StringToHGlobalAnsi(addressBox->Text)).ToPointer());

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
		firstNameError->Text = "  S";
		lastNameError->Text = "  ";
		emailError->Text = "  ";
		passportError->Text = "  ";
		label2->Text = "  ";
		countryError->Text = "  ";

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
			label2->Text = "!!!";
		}
		if (phone == "") {
			phone = "0";
		}
		if (resCountry == "") {
			countryError->Text = "!!!";
		}

		if (firstName != "" && lastName != "" && email != "" && passport != "" && country != "") {
			string query = "INSERT INTO `logo_university`.`instructor` (`first_name`, `last_name`, `dept_name`, `email`, `password`, `phone_number`, `office`, `passport_no`, `country`, `country_of_res`, `city`, `street`, `address`, `yob`, `mob`, `dob`) VALUES"
				"(\"" + firstName + "\",\"" + lastName + "\",\"" + department + "\",\"" + email + "\",\"" + passport + "\"," + phone + ", \"" + office + "\", \"" + passport + "\", \"" + country + "\",\"" + resCountry + "\",\"" + city + "\",\"" + street + "\", \"" + address + "\"," + year + +",\"" + month + "\"," + day + ");";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				this->Close();
			}
		}

	}
};
}
