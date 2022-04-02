#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <mysql.h>

std::string idS;

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	/// <summary>
	/// Summary for changePassword
	/// </summary>
	public ref class changePassword : public System::Windows::Forms::Form
	{
	public:
		changePassword(char * idPara)
		{

			InitializeComponent();
			string i(idPara);
			idS = i;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~changePassword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ passwordBox;
	protected:

	private: System::Windows::Forms::Button^ ChangePasswordButton;
	private: System::Windows::Forms::Label^ passwordError;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->ChangePasswordButton = (gcnew System::Windows::Forms::Button());
			this->passwordError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(48, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"password";
			// 
			// passwordBox
			// 
			this->passwordBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordBox->Location = System::Drawing::Point(111, 52);
			this->passwordBox->MaxLength = 10;
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->Size = System::Drawing::Size(179, 20);
			this->passwordBox->TabIndex = 1;
			// 
			// ChangePasswordButton
			// 
			this->ChangePasswordButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ChangePasswordButton->BackColor = System::Drawing::Color::White;
			this->ChangePasswordButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ChangePasswordButton->Location = System::Drawing::Point(51, 109);
			this->ChangePasswordButton->Name = L"ChangePasswordButton";
			this->ChangePasswordButton->Size = System::Drawing::Size(239, 36);
			this->ChangePasswordButton->TabIndex = 2;
			this->ChangePasswordButton->Text = L"Change Password";
			this->ChangePasswordButton->UseVisualStyleBackColor = false;
			this->ChangePasswordButton->Click += gcnew System::EventHandler(this, &changePassword::ChangePasswordButton_Click);
			// 
			// passwordError
			// 
			this->passwordError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordError->AutoSize = true;
			this->passwordError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordError->Location = System::Drawing::Point(108, 91);
			this->passwordError->Name = L"passwordError";
			this->passwordError->Size = System::Drawing::Size(88, 15);
			this->passwordError->TabIndex = 3;
			this->passwordError->Text = L"                           ";
			// 
			// changePassword
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(387, 180);
			this->Controls->Add(this->passwordError);
			this->Controls->Add(this->ChangePasswordButton);
			this->Controls->Add(this->passwordBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"changePassword";
			this->Text = L"Change Password";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ChangePasswordButton_Click(System::Object^ sender, System::EventArgs^ e) {
		passwordError->Text = "  ";
		if (passwordBox->Text == "") {
			passwordBox->Text = "enter a password";
		}
		else {
			
			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			if (con) {
				string password((const char*)(Marshal::StringToHGlobalAnsi(passwordBox->Text)).ToPointer());
				string query = "update student set password = \"" + password + "\" where id = " + idS + "; ";

				int check = mysql_query(con, query.c_str());
				if (!check) {
					this->Close();
				}
			}
		}
	}
};
}
