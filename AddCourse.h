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
	using namespace System::Runtime::InteropServices;
	using namespace std;
	string coursecode;

	/// <summary>
	/// Summary for AddCourse
	/// </summary>
	public ref class AddCourse : public System::Windows::Forms::Form
	{
		MYSQL* con;
		MYSQL_RES* res;
	private: System::Windows::Forms::Label^ added;
		   MYSQL_ROW row;
		   
	public:
		AddCourse(string facultyNamePara)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->editCourseButton->Location = System::Drawing::Point(5157, 5255);
			con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			string query = "select dept_name from department where faculty like \"%" + facultyNamePara + "%\";";
			cout << query << endl;
			int check = mysql_query(con, query.c_str());
			if (!check) {
				res = mysql_store_result(con);
				while ((row = mysql_fetch_row(res)) != NULL) {
					cout << row[0] << endl;
					departmentBox->Items->Add(gcnew String(row[0]));
				}
			}
			mysql_free_result(res);
		}
		AddCourse(string codePara , int random) {
			coursecode = codePara;
			InitializeComponent();
			this->addCourseButton->Location = System::Drawing::Point(5157, 5255);
			con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			string query = "select * from course where course_code like \"%" + coursecode + "%\";";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				res = mysql_store_result(con);
				row = mysql_fetch_row(res);
				titleBox->Text = gcnew String(row[1]);
				courseCodeBox->Text = gcnew String(row[0]);
				departmentBox->Text = gcnew String(row[2]);
				creditBox->Text = gcnew String(row[3]);
			}
			this->Text = L"Edit Course";
			mysql_free_result(res);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ titleBox;

	protected:

	private: System::Windows::Forms::TextBox^ courseCodeBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ creditBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ addCourseButton;
	private: System::Windows::Forms::ComboBox^ departmentBox;
	private: System::Windows::Forms::Button^ editCourseButton;
	private: System::Windows::Forms::Label^ deptError;
	private: System::Windows::Forms::Label^ codeError;
	private: System::Windows::Forms::Label^ titleError;
	private: System::Windows::Forms::Label^ creditError;

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
			this->titleBox = (gcnew System::Windows::Forms::TextBox());
			this->courseCodeBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->creditBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addCourseButton = (gcnew System::Windows::Forms::Button());
			this->departmentBox = (gcnew System::Windows::Forms::ComboBox());
			this->editCourseButton = (gcnew System::Windows::Forms::Button());
			this->deptError = (gcnew System::Windows::Forms::Label());
			this->codeError = (gcnew System::Windows::Forms::Label());
			this->titleError = (gcnew System::Windows::Forms::Label());
			this->creditError = (gcnew System::Windows::Forms::Label());
			this->added = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(94, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course title";
			// 
			// titleBox
			// 
			this->titleBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleBox->Location = System::Drawing::Point(167, 74);
			this->titleBox->Name = L"titleBox";
			this->titleBox->Size = System::Drawing::Size(163, 20);
			this->titleBox->TabIndex = 1;
			// 
			// courseCodeBox
			// 
			this->courseCodeBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->courseCodeBox->Location = System::Drawing::Point(167, 118);
			this->courseCodeBox->MaxLength = 10;
			this->courseCodeBox->Name = L"courseCodeBox";
			this->courseCodeBox->Size = System::Drawing::Size(163, 20);
			this->courseCodeBox->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(89, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Course Code";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(90, 162);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Department";
			// 
			// creditBox
			// 
			this->creditBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->creditBox->Location = System::Drawing::Point(167, 195);
			this->creditBox->Name = L"creditBox";
			this->creditBox->Size = System::Drawing::Size(46, 20);
			this->creditBox->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(118, 195);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 15);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Credit";
			// 
			// addCourseButton
			// 
			this->addCourseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addCourseButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addCourseButton->Location = System::Drawing::Point(148, 255);
			this->addCourseButton->Name = L"addCourseButton";
			this->addCourseButton->Size = System::Drawing::Size(161, 52);
			this->addCourseButton->TabIndex = 8;
			this->addCourseButton->Text = L"Add Course";
			this->addCourseButton->UseVisualStyleBackColor = true;
			this->addCourseButton->Click += gcnew System::EventHandler(this, &AddCourse::addCourseButton_Click);
			// 
			// departmentBox
			// 
			this->departmentBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->departmentBox->FormattingEnabled = true;
			this->departmentBox->Location = System::Drawing::Point(167, 160);
			this->departmentBox->Name = L"departmentBox";
			this->departmentBox->Size = System::Drawing::Size(163, 21);
			this->departmentBox->TabIndex = 9;
			// 
			// editCourseButton
			// 
			this->editCourseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->editCourseButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editCourseButton->Location = System::Drawing::Point(157, 255);
			this->editCourseButton->Name = L"editCourseButton";
			this->editCourseButton->Size = System::Drawing::Size(138, 52);
			this->editCourseButton->TabIndex = 10;
			this->editCourseButton->Text = L"Edit Course";
			this->editCourseButton->UseVisualStyleBackColor = true;
			this->editCourseButton->Click += gcnew System::EventHandler(this, &AddCourse::editCourseButton_Click);
			// 
			// deptError
			// 
			this->deptError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->deptError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deptError->Location = System::Drawing::Point(345, 162);
			this->deptError->Name = L"deptError";
			this->deptError->Size = System::Drawing::Size(165, 19);
			this->deptError->TabIndex = 11;
			this->deptError->Text = L"       ";
			// 
			// codeError
			// 
			this->codeError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->codeError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->codeError->Location = System::Drawing::Point(336, 118);
			this->codeError->Name = L"codeError";
			this->codeError->Size = System::Drawing::Size(165, 19);
			this->codeError->TabIndex = 12;
			this->codeError->Text = L"       ";
			// 
			// titleError
			// 
			this->titleError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleError->Location = System::Drawing::Point(336, 72);
			this->titleError->Name = L"titleError";
			this->titleError->Size = System::Drawing::Size(165, 19);
			this->titleError->TabIndex = 13;
			this->titleError->Text = L"       ";
			// 
			// creditError
			// 
			this->creditError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->creditError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->creditError->Location = System::Drawing::Point(336, 191);
			this->creditError->Name = L"creditError";
			this->creditError->Size = System::Drawing::Size(165, 19);
			this->creditError->TabIndex = 14;
			this->creditError->Text = L"       ";
			// 
			// added
			// 
			this->added->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->added->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->added->Location = System::Drawing::Point(49, 233);
			this->added->Name = L"added";
			this->added->Size = System::Drawing::Size(165, 19);
			this->added->TabIndex = 15;
			this->added->Text = L"       ";
			// 
			// AddCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(538, 344);
			this->Controls->Add(this->added);
			this->Controls->Add(this->creditError);
			this->Controls->Add(this->titleError);
			this->Controls->Add(this->codeError);
			this->Controls->Add(this->deptError);
			this->Controls->Add(this->editCourseButton);
			this->Controls->Add(this->departmentBox);
			this->Controls->Add(this->addCourseButton);
			this->Controls->Add(this->creditBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->courseCodeBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->titleBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"AddCourse";
			this->Text = L"Add Course";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addCourseButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string title((const char*)(Marshal::StringToHGlobalAnsi(titleBox->Text)).ToPointer());
		string code((const char*)(Marshal::StringToHGlobalAnsi(courseCodeBox->Text)).ToPointer());
		string dept((const char*)(Marshal::StringToHGlobalAnsi(departmentBox->Text)).ToPointer());
		string credit((const char*)(Marshal::StringToHGlobalAnsi(creditBox->Text)).ToPointer());
		added->Text = "  ";
		titleError->Text = "  ";
		codeError->Text = "  ";
		creditError->Text = "  ";
		deptError->Text = "  ";

		if (title == "") {
			titleError->Text = "!!!";
		}
		if (code == "") {
			codeError->Text = "!!!";
		}
		if (dept == "") {
			deptError->Text = "!!!";
		}
		if (credit == "") {
			creditError->Text = "!!!";
		}
		if (title != "" && code != "" && dept != "" & credit != "") {
			string query = "insert into course(course_code, title, dept_name,credit) values (\"" + code + "\", \"" + title + "\", \"" + dept + "\", " + credit + ");";
			int check = mysql_query(con, query.c_str());
			if (check) {
				added->Text = "course code invalid";
			}
			else {
				added->Text = "Added.";
				this->Close();
			}
		}
	}
private: System::Void editCourseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	string title((const char*)(Marshal::StringToHGlobalAnsi(titleBox->Text)).ToPointer());
	string code((const char*)(Marshal::StringToHGlobalAnsi(courseCodeBox->Text)).ToPointer());
	string dept((const char*)(Marshal::StringToHGlobalAnsi(departmentBox->Text)).ToPointer());
	string credit((const char*)(Marshal::StringToHGlobalAnsi(creditBox->Text)).ToPointer());
	added->Text = "  ";
	titleError->Text = "  ";
	codeError->Text = "  ";
	creditError->Text = "  ";
	deptError->Text = "  ";

	if (title == "") {
		titleError->Text = "!!!";
	}
	if (code == "") {
		codeError->Text = "!!!";
	}
	if (dept == "") {
		deptError->Text = "!!!";
	}
	if (credit == "") {
		creditError->Text = "!!!";
	}
	if (title != "" && code != "" && dept != "" & credit != "") {
		string query = "update course set title = \"" + title + "\", course_code = \"" + code + "\", credit = \"" + credit + "\" where course_code = \"" + coursecode + "\";";
		int check = mysql_query(con, query.c_str());
		if (!check) {
			added->Text = "edited";
			this->Close();
		}
		else {
			added->Text = "not edited";
		}
	}
}
};
}
