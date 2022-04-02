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

	/// <summary>
	/// Summary for Course
	/// </summary>
	public ref class Course : public System::Windows::Forms::Form
	{
	public:

		Course(char* courseCode, int yearPara, String^ semesterPara, char* group)
		{
			InitializeComponent();
			//------------------

			string semesterString((const char*)(Marshal::StringToHGlobalAnsi(semesterPara)).ToPointer());

			string groupNum(group);

			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			string courseCodeString(courseCode);
			if (con) {
				string query = "select first_name,last_name, textbook, title, office,email from teaches,instructor,course "
					"where teaches.course_code = \"" + courseCodeString + "\" and teaches.course_code = course.course_code"
					" and course.course_code = \"" + courseCodeString +
					"\" and semester = \"" + semesterString + "\" and year = " + to_string(yearPara) +
					" and group_number = " + groupNum + " and teaches.i_id = instructor.id;";
				int check = mysql_query(con, query.c_str());

				if (!check) {
					MYSQL_RES* res = mysql_store_result(con);
					MYSQL_ROW row = mysql_fetch_row(res);
					if ((mysql_num_rows(res)) != 0) {
						char fullName[50] = "";
						strcat(fullName, row[0]);
						strcat(fullName, " ");
						strcat(fullName, row[1]);
						String^ fullNameString = gcnew String(fullName);
						this->instructor->Text = fullNameString;
						this->textbook->Text = gcnew String(row[2]);
						this->title->Text = gcnew String(row[3]);
						this->Text = gcnew String(row[3]);
						this->office->Text = gcnew String(row[4]);
						this->email->Text = gcnew String(row[5]);
					}
				}
				query = "select first_name, last_name, id from takes,student where takes.course_code = \"" + courseCodeString +
					"\" and student.id = takes.s_id and semester = \"" + semesterString + "\" and year = " + to_string(yearPara) + " ;";
				check = mysql_query(con, query.c_str());

				if (!check) {
					MYSQL_RES* res = mysql_store_result(con);
					MYSQL_ROW row;
					while ((row = mysql_fetch_row(res)) != NULL) {

						char studentName[50] = "";
						strcat(studentName, row[0]);
						strcat(studentName, " ");
						strcat(studentName, row[1]);
						strcat(studentName, " ");
						strcat(studentName, row[2]);

						String^ studentNameString = gcnew String(studentName);
						strcpy(studentName, "");
						this->studentList->Items->Add(studentNameString);
					}
				}

				query = "select comment from course where course_code = \"" + courseCodeString + "\" ;";
				check = mysql_query(con, query.c_str());
				if (!check) {
					MYSQL_RES* res = mysql_store_result(con);
					int count = mysql_num_rows(res);
					if (count > 0) {
						MYSQL_ROW row = mysql_fetch_row(res);
						this->comment->Text = gcnew String(row[0]);
					}
				}

			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Course()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	private: System::Windows::Forms::Label^ instructor;
	private: System::Windows::Forms::ListBox^ studentList;

	private: System::Windows::Forms::Label^ comment;

	private: System::Windows::Forms::Label^ textbook;

	private: System::Windows::Forms::Label^ email;
private: System::Windows::Forms::Label^ title;
private: System::Windows::Forms::Label^ office;






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
			this->instructor = (gcnew System::Windows::Forms::Label());
			this->studentList = (gcnew System::Windows::Forms::ListBox());
			this->comment = (gcnew System::Windows::Forms::Label());
			this->textbook = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::Label());
			this->title = (gcnew System::Windows::Forms::Label());
			this->office = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// instructor
			// 
			this->instructor->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->instructor->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instructor->Location = System::Drawing::Point(12, 48);
			this->instructor->Name = L"instructor";
			this->instructor->Size = System::Drawing::Size(369, 26);
			this->instructor->TabIndex = 1;
			this->instructor->Text = L"instructor";
			// 
			// studentList
			// 
			this->studentList->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentList->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->studentList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->studentList->FormattingEnabled = true;
			this->studentList->ItemHeight = 18;
			this->studentList->Location = System::Drawing::Point(387, 36);
			this->studentList->Name = L"studentList";
			this->studentList->Size = System::Drawing::Size(285, 274);
			this->studentList->TabIndex = 2;
			// 
			// comment
			// 
			this->comment->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comment->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->comment->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->comment->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comment->Location = System::Drawing::Point(12, 206);
			this->comment->Name = L"comment";
			this->comment->Size = System::Drawing::Size(369, 190);
			this->comment->TabIndex = 3;
			this->comment->Text = L"       ";
			// 
			// textbook
			// 
			this->textbook->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textbook->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textbook->Location = System::Drawing::Point(12, 177);
			this->textbook->Name = L"textbook";
			this->textbook->Size = System::Drawing::Size(369, 19);
			this->textbook->TabIndex = 4;
			this->textbook->Text = L"textbook";
			// 
			// email
			// 
			this->email->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->email->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->email->Location = System::Drawing::Point(17, 78);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(364, 19);
			this->email->TabIndex = 5;
			this->email->Text = L"email";
			// 
			// title
			// 
			this->title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->Location = System::Drawing::Point(12, 147);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(369, 19);
			this->title->TabIndex = 6;
			this->title->Text = L"title";
			// 
			// office
			// 
			this->office->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->office->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->office->Location = System::Drawing::Point(12, 114);
			this->office->Name = L"office";
			this->office->Size = System::Drawing::Size(369, 19);
			this->office->TabIndex = 7;
			this->office->Text = L"office";
			// 
			// Course
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(693, 405);
			this->Controls->Add(this->office);
			this->Controls->Add(this->title);
			this->Controls->Add(this->email);
			this->Controls->Add(this->textbook);
			this->Controls->Add(this->comment);
			this->Controls->Add(this->studentList);
			this->Controls->Add(this->instructor);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Course";
			this->Text = L"Course";
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
