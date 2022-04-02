#pragma once
#include <mysql.h>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	string idI;

	/// <summary>
	/// Summary for iUpdateDetails
	/// </summary>
	public ref class iUpdateDetails : public System::Windows::Forms::Form
	{
	public:
		iUpdateDetails(string idPara)
		{
			idI = idPara;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			string query = "select first_name, last_name,phone_number,email,country_of_res,city,street,address from instructor where id =" + idI + " ;";
			cout << query << endl;
			int check = mysql_query(con, query.c_str());
			if (!check) {
				cout << "inside";
				MYSQL_RES* res = mysql_store_result(con);
				MYSQL_ROW row = mysql_fetch_row(res);
				this->firstnamebox->Text = gcnew String(row[0]);
				this->lastnameBox->Text = gcnew String(row[1]);
				this->phoneNoBox->Text = gcnew String(row[2]);
				this->emailBox->Text = gcnew String(row[3]);
				this->countryBox->Text = gcnew String(row[4]);
				this->cityBox->Text = gcnew String(row[5]);
				this->streetBox->Text = gcnew String(row[6]);
				this->addressBox->Text = gcnew String(row[7]);
				mysql_free_result(res);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~iUpdateDetails()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label13;
	protected:
	private: System::Windows::Forms::Label^ emailError;
	private: System::Windows::Forms::Label^ lastnameError;
	private: System::Windows::Forms::Label^ firstnameError;
	private: System::Windows::Forms::Button^ UpdateButton;
	private: System::Windows::Forms::TextBox^ addressBox;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ streetBox;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ cityBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ countryBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ emailBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ phoneNoBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ lastnameBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ firstnamebox;
	private: System::Windows::Forms::Label^ label1;

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
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->emailError = (gcnew System::Windows::Forms::Label());
			this->lastnameError = (gcnew System::Windows::Forms::Label());
			this->firstnameError = (gcnew System::Windows::Forms::Label());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->addressBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->streetBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cityBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->countryBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->emailBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->phoneNoBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lastnameBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->firstnamebox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(188, 16);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(152, 15);
			this->label13->TabIndex = 43;
			this->label13->Text = L"Columns with * must be filled";
			// 
			// emailError
			// 
			this->emailError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailError->AutoSize = true;
			this->emailError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailError->Location = System::Drawing::Point(403, 177);
			this->emailError->Name = L"emailError";
			this->emailError->Size = System::Drawing::Size(22, 15);
			this->emailError->TabIndex = 42;
			this->emailError->Text = L"     ";
			// 
			// lastnameError
			// 
			this->lastnameError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lastnameError->AutoSize = true;
			this->lastnameError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastnameError->Location = System::Drawing::Point(403, 98);
			this->lastnameError->Name = L"lastnameError";
			this->lastnameError->Size = System::Drawing::Size(22, 15);
			this->lastnameError->TabIndex = 41;
			this->lastnameError->Text = L"     ";
			// 
			// firstnameError
			// 
			this->firstnameError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->firstnameError->AutoSize = true;
			this->firstnameError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->firstnameError->Location = System::Drawing::Point(403, 58);
			this->firstnameError->Name = L"firstnameError";
			this->firstnameError->Size = System::Drawing::Size(16, 15);
			this->firstnameError->TabIndex = 40;
			this->firstnameError->Text = L"   ";
			// 
			// UpdateButton
			// 
			this->UpdateButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->UpdateButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UpdateButton->Location = System::Drawing::Point(171, 372);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(209, 30);
			this->UpdateButton->TabIndex = 39;
			this->UpdateButton->Text = L"Update";
			this->UpdateButton->UseVisualStyleBackColor = true;
			this->UpdateButton->Click += gcnew System::EventHandler(this, &iUpdateDetails::UpdateButton_Click);
			// 
			// addressBox
			// 
			this->addressBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addressBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addressBox->Location = System::Drawing::Point(171, 339);
			this->addressBox->Name = L"addressBox";
			this->addressBox->Size = System::Drawing::Size(209, 21);
			this->addressBox->TabIndex = 38;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(122, 342);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(43, 15);
			this->label8->TabIndex = 37;
			this->label8->Text = L"address";
			// 
			// streetBox
			// 
			this->streetBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->streetBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->streetBox->Location = System::Drawing::Point(171, 300);
			this->streetBox->Name = L"streetBox";
			this->streetBox->Size = System::Drawing::Size(209, 21);
			this->streetBox->TabIndex = 36;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(131, 306);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 15);
			this->label7->TabIndex = 35;
			this->label7->Text = L"street";
			// 
			// cityBox
			// 
			this->cityBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cityBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cityBox->Location = System::Drawing::Point(171, 259);
			this->cityBox->Name = L"cityBox";
			this->cityBox->Size = System::Drawing::Size(209, 21);
			this->cityBox->TabIndex = 34;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(74, 262);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 15);
			this->label6->TabIndex = 33;
			this->label6->Text = L"city of resisdence";
			// 
			// countryBox
			// 
			this->countryBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->countryBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->countryBox->Location = System::Drawing::Point(171, 219);
			this->countryBox->Name = L"countryBox";
			this->countryBox->Size = System::Drawing::Size(209, 21);
			this->countryBox->TabIndex = 32;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(55, 222);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 15);
			this->label5->TabIndex = 31;
			this->label5->Text = L"country of resisdence";
			// 
			// emailBox
			// 
			this->emailBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailBox->Location = System::Drawing::Point(171, 177);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(209, 21);
			this->emailBox->TabIndex = 30;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(133, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 15);
			this->label4->TabIndex = 29;
			this->label4->Text = L"email*";
			// 
			// phoneNoBox
			// 
			this->phoneNoBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phoneNoBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneNoBox->Location = System::Drawing::Point(171, 136);
			this->phoneNoBox->Name = L"phoneNoBox";
			this->phoneNoBox->Size = System::Drawing::Size(209, 21);
			this->phoneNoBox->TabIndex = 28;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(89, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 15);
			this->label3->TabIndex = 27;
			this->label3->Text = L"phone number";
			// 
			// lastnameBox
			// 
			this->lastnameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lastnameBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastnameBox->Location = System::Drawing::Point(171, 95);
			this->lastnameBox->Name = L"lastnameBox";
			this->lastnameBox->Size = System::Drawing::Size(209, 21);
			this->lastnameBox->TabIndex = 26;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(116, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 15);
			this->label2->TabIndex = 25;
			this->label2->Text = L"lastname*";
			// 
			// firstnamebox
			// 
			this->firstnamebox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->firstnamebox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->firstnamebox->Location = System::Drawing::Point(171, 55);
			this->firstnamebox->Name = L"firstnamebox";
			this->firstnamebox->Size = System::Drawing::Size(209, 21);
			this->firstnamebox->TabIndex = 24;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(110, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 15);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Firstname*";
			// 
			// iUpdateDetails
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(619, 414);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->emailError);
			this->Controls->Add(this->lastnameError);
			this->Controls->Add(this->firstnameError);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->addressBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->streetBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->cityBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->countryBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->emailBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->phoneNoBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lastnameBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->firstnamebox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"iUpdateDetails";
			this->Text = L"UpdateDetails";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UpdateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		firstnameError->Text = " ";
		lastnameError->Text = "  ";
		emailError->Text = "  ";

		if (firstnamebox->Text == "")
			firstnameError->Text = "enter your firstname";
		if (lastnameBox->Text == "")
			lastnameError->Text = "enter your lastname";
		if (emailBox->Text == "")
			emailError->Text = "enter your email";
		if (firstnamebox->Text != "" && lastnameBox->Text != "" && emailBox->Text != "") {
			string firstName((const char*)(Marshal::StringToHGlobalAnsi(firstnamebox->Text)).ToPointer());
			string lastName((const char*)(Marshal::StringToHGlobalAnsi(lastnameBox->Text)).ToPointer());
			string phoneNo((const char*)(Marshal::StringToHGlobalAnsi(phoneNoBox->Text)).ToPointer());
			string email((const char*)(Marshal::StringToHGlobalAnsi(emailBox->Text)).ToPointer());
			string country((const char*)(Marshal::StringToHGlobalAnsi(countryBox->Text)).ToPointer());
			string city((const char*)(Marshal::StringToHGlobalAnsi(cityBox->Text)).ToPointer());
			string street((const char*)(Marshal::StringToHGlobalAnsi(streetBox->Text)).ToPointer());
			string address((const char*)(Marshal::StringToHGlobalAnsi(addressBox->Text)).ToPointer());

			if (phoneNo == "") {
				phoneNo = "0";
			}

			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			string query = "update instructor set "
				"first_name = \"" + firstName + "\","
				"last_name = \"" + lastName + "\","
				"phone_number = \"" + phoneNo + "\","
				"email = \"" + email + "\","
				"country_of_res = \"" + country + "\","
				"city = \"" + city + "\","
				"address = \"" + address + "\","
				"street = \"" + street + "\""
				"where id = " + idI + ";";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				this->Close();
			}
		}
	}
};
}
