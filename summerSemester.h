#pragma once
#include <string>
#include <mysql.h>

std::string facultyNameStudent;

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
	/// Summary for summerSemester
	/// </summary>
	public ref class summerSemester : public System::Windows::Forms::Form
	{
	public:
		summerSemester(string facultyNamePara)
		{
			facultyNameStudent = facultyNamePara;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~summerSemester()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ studentId;


	private: System::Windows::Forms::Label^ studentIdError;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->studentId = (gcnew System::Windows::Forms::TextBox());
			this->studentIdError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(117, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(152, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &summerSemester::button1_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(54, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"student id";
			// 
			// studentId
			// 
			this->studentId->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentId->Location = System::Drawing::Point(120, 48);
			this->studentId->MaxLength = 10;
			this->studentId->Name = L"studentId";
			this->studentId->Size = System::Drawing::Size(203, 20);
			this->studentId->TabIndex = 2;
			// 
			// studentIdError
			// 
			this->studentIdError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentIdError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->studentIdError->Location = System::Drawing::Point(54, 78);
			this->studentIdError->Name = L"studentIdError";
			this->studentIdError->Size = System::Drawing::Size(269, 42);
			this->studentIdError->TabIndex = 3;
			this->studentIdError->Text = L"        ";
			// 
			// summerSemester
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(427, 156);
			this->Controls->Add(this->studentIdError);
			this->Controls->Add(this->studentId);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"summerSemester";
			this->Text = L"summerSemester";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	studentIdError->Text = " ";
	string id((const char*)(Marshal::StringToHGlobalAnsi(studentId->Text)).ToPointer());

	MYSQL* con = mysql_init(NULL);
	con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
	if (con) {
		string query = "select * from student,department where id = " + id + " and student.dept_name = department.dept_name and faculty = \"" + facultyNameStudent + "\";";
		int check = mysql_query(con,query.c_str());
		if (!check) {
			string query1 = "update student set current_semester = true, semester_no = semester_no + 1 where id = 1 ;";
			if (con) {
				mysql_query(con, query1.c_str());
			}
		}
		else {
			studentIdError->Text = "not in faculty";
		}
	}

}
};
}
