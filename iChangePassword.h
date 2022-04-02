#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <mysql.h>

std::string idI;

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
	/// Summary for iChangePassword
	/// </summary>
	public ref class iChangePassword : public System::Windows::Forms::Form
	{
	public:
		iChangePassword(string idPara)
		{
			idI = idPara;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~iChangePassword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ changePasswordButton;
	private: System::Windows::Forms::TextBox^ password;
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
			this->changePasswordButton = (gcnew System::Windows::Forms::Button());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->passwordError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(44, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"password";
			// 
			// changePasswordButton
			// 
			this->changePasswordButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->changePasswordButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->changePasswordButton->Location = System::Drawing::Point(44, 79);
			this->changePasswordButton->Name = L"changePasswordButton";
			this->changePasswordButton->Size = System::Drawing::Size(268, 23);
			this->changePasswordButton->TabIndex = 1;
			this->changePasswordButton->Text = L"Change Password";
			this->changePasswordButton->UseVisualStyleBackColor = true;
			this->changePasswordButton->Click += gcnew System::EventHandler(this, &iChangePassword::changePasswordButton_Click);
			// 
			// password
			// 
			this->password->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->password->Location = System::Drawing::Point(99, 27);
			this->password->MaxLength = 10;
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(213, 20);
			this->password->TabIndex = 2;
			// 
			// passwordError
			// 
			this->passwordError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordError->Location = System::Drawing::Point(44, 50);
			this->passwordError->Name = L"passwordError";
			this->passwordError->Size = System::Drawing::Size(265, 26);
			this->passwordError->TabIndex = 3;
			this->passwordError->Text = L"               ";
			// 
			// iChangePassword
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(362, 126);
			this->Controls->Add(this->passwordError);
			this->Controls->Add(this->password);
			this->Controls->Add(this->changePasswordButton);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"iChangePassword";
			this->Text = L"Change Password";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void changePasswordButton_Click(System::Object^ sender, System::EventArgs^ e) {
		passwordError->Text = "  ";
		if (password->Text == "") {
			passwordError->Text = "enter a password";
		}
		else {

			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			if (con) {
				string passwordText((const char*)(Marshal::StringToHGlobalAnsi(password->Text)).ToPointer());
				string query = "update instructor set password = \"" + passwordText + "\" where id = " + idI + "; ";

				int check = mysql_query(con, query.c_str());
				if (!check) {
					query = "update coordinator set password = \"" + passwordText + "\" where i_id = " + idI + "; ";
					check = mysql_query(con, query.c_str());
					if (!check) {
						this->Close();
					}
					else {
						passwordError->Text = "not changed";
					}
				}
				
			}
		}
	}
	};
}
