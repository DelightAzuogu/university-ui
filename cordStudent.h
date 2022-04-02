#pragma once
#include <mysql.h>
#include <string>
#include <cctype>
#include <cstring>
#include <iostream>
#include "coordAddStudent.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Runtime::InteropServices;


	string FacultyName;
	MYSQL* con;

	/// <summary>
	/// Summary for cordStudent
	/// </summary>
	public ref class cordStudent : public System::Windows::Forms::Form
	{
	public:
		cordStudent(string facultyNamePara)
		{
			FacultyName = facultyNamePara;
			con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~cordStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ studentNo;
	private: System::Windows::Forms::CheckBox^ freezeCheck;
	private: System::Windows::Forms::CheckBox^ inactiveCheck;
	private: System::Windows::Forms::CheckBox^ graduateCheck;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ studentError;
	private: System::Windows::Forms::Button^ editStudentButton;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ unfreezeCheck;
	private: System::Windows::Forms::CheckBox^ activateCheck;


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
			this->studentNo = (gcnew System::Windows::Forms::TextBox());
			this->freezeCheck = (gcnew System::Windows::Forms::CheckBox());
			this->inactiveCheck = (gcnew System::Windows::Forms::CheckBox());
			this->graduateCheck = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->studentError = (gcnew System::Windows::Forms::Label());
			this->editStudentButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->unfreezeCheck = (gcnew System::Windows::Forms::CheckBox());
			this->activateCheck = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(97, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(252, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add Student";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &cordStudent::button1_Click);
			// 
			// studentNo
			// 
			this->studentNo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentNo->Location = System::Drawing::Point(117, 20);
			this->studentNo->MaxLength = 10;
			this->studentNo->Name = L"studentNo";
			this->studentNo->Size = System::Drawing::Size(209, 21);
			this->studentNo->TabIndex = 1;
			// 
			// freezeCheck
			// 
			this->freezeCheck->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->freezeCheck->AutoSize = true;
			this->freezeCheck->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->freezeCheck->Location = System::Drawing::Point(22, 79);
			this->freezeCheck->Name = L"freezeCheck";
			this->freezeCheck->Size = System::Drawing::Size(60, 19);
			this->freezeCheck->TabIndex = 2;
			this->freezeCheck->Text = L"freeze";
			this->freezeCheck->UseVisualStyleBackColor = true;
			this->freezeCheck->Click += gcnew System::EventHandler(this, &cordStudent::freezeCheck_Click);
			// 
			// inactiveCheck
			// 
			this->inactiveCheck->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->inactiveCheck->AutoSize = true;
			this->inactiveCheck->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inactiveCheck->Location = System::Drawing::Point(151, 79);
			this->inactiveCheck->Name = L"inactiveCheck";
			this->inactiveCheck->Size = System::Drawing::Size(68, 19);
			this->inactiveCheck->TabIndex = 3;
			this->inactiveCheck->Text = L"Inactive";
			this->inactiveCheck->UseVisualStyleBackColor = true;
			this->inactiveCheck->Click += gcnew System::EventHandler(this, &cordStudent::inactiveCheck_Click);
			// 
			// graduateCheck
			// 
			this->graduateCheck->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->graduateCheck->AutoSize = true;
			this->graduateCheck->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graduateCheck->Location = System::Drawing::Point(280, 79);
			this->graduateCheck->Name = L"graduateCheck";
			this->graduateCheck->Size = System::Drawing::Size(76, 19);
			this->graduateCheck->TabIndex = 4;
			this->graduateCheck->Text = L"Graduate";
			this->graduateCheck->UseVisualStyleBackColor = true;
			this->graduateCheck->Click += gcnew System::EventHandler(this, &cordStudent::graduateCheck_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(19, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 15);
			this->label1->TabIndex = 5;
			this->label1->Text = L"student number";
			// 
			// studentError
			// 
			this->studentError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentError->AutoSize = true;
			this->studentError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->studentError->Location = System::Drawing::Point(19, 61);
			this->studentError->Name = L"studentError";
			this->studentError->Size = System::Drawing::Size(28, 15);
			this->studentError->TabIndex = 6;
			this->studentError->Text = L"       ";
			// 
			// editStudentButton
			// 
			this->editStudentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->editStudentButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editStudentButton->Location = System::Drawing::Point(74, 145);
			this->editStudentButton->Name = L"editStudentButton";
			this->editStudentButton->Size = System::Drawing::Size(252, 48);
			this->editStudentButton->TabIndex = 7;
			this->editStudentButton->Text = L"Edit Student";
			this->editStudentButton->UseVisualStyleBackColor = true;
			this->editStudentButton->Click += gcnew System::EventHandler(this, &cordStudent::editStudentButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->unfreezeCheck);
			this->groupBox1->Controls->Add(this->activateCheck);
			this->groupBox1->Controls->Add(this->editStudentButton);
			this->groupBox1->Controls->Add(this->studentError);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->graduateCheck);
			this->groupBox1->Controls->Add(this->inactiveCheck);
			this->groupBox1->Controls->Add(this->freezeCheck);
			this->groupBox1->Controls->Add(this->studentNo);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(23, 128);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(402, 230);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Edit Student";
			// 
			// unfreezeCheck
			// 
			this->unfreezeCheck->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->unfreezeCheck->AutoSize = true;
			this->unfreezeCheck->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->unfreezeCheck->Location = System::Drawing::Point(84, 120);
			this->unfreezeCheck->Name = L"unfreezeCheck";
			this->unfreezeCheck->Size = System::Drawing::Size(75, 19);
			this->unfreezeCheck->TabIndex = 9;
			this->unfreezeCheck->Text = L"Unfreeze";
			this->unfreezeCheck->UseVisualStyleBackColor = true;
			this->unfreezeCheck->Click += gcnew System::EventHandler(this, &cordStudent::unfreezeCheck_Click);
			// 
			// activateCheck
			// 
			this->activateCheck->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->activateCheck->AutoSize = true;
			this->activateCheck->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->activateCheck->Location = System::Drawing::Point(233, 120);
			this->activateCheck->Name = L"activateCheck";
			this->activateCheck->Size = System::Drawing::Size(70, 19);
			this->activateCheck->TabIndex = 8;
			this->activateCheck->Text = L"Activate";
			this->activateCheck->UseVisualStyleBackColor = true;
			this->activateCheck->Click += gcnew System::EventHandler(this, &cordStudent::activateCheck_Click);
			// 
			// cordStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(453, 375);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"cordStudent";
			this->Text = L"Student";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void freezeCheck_Click(System::Object^ sender, System::EventArgs^ e) {
		freezeCheck->Checked = true;
		inactiveCheck->Checked = false;
		graduateCheck->Checked = false;
		activateCheck->Checked = false;
		unfreezeCheck->Checked = false;
	}

private: System::Void inactiveCheck_Click(System::Object^ sender, System::EventArgs^ e) {
	freezeCheck->Checked = false;
	inactiveCheck->Checked = true;
	graduateCheck->Checked = false;
	activateCheck->Checked = false;
	unfreezeCheck->Checked = false;
}
private: System::Void graduateCheck_Click(System::Object^ sender, System::EventArgs^ e) {
	freezeCheck->Checked = false;
	inactiveCheck->Checked = false;
	graduateCheck->Checked = true;
	activateCheck->Checked = false;
	unfreezeCheck->Checked = false;
}
private: System::Void editStudentButton_Click(System::Object^ sender, System::EventArgs^ e) {
	studentError->Text = "  ";

	if (graduateCheck->Checked == false && inactiveCheck->Checked == false && freezeCheck->Checked == false&& unfreezeCheck->Checked == false && activateCheck->Checked == false) {
		studentError->Text = "choose an edit mood";
	}
	else {
		if (studentNo->Text == "") {
			studentError->Text = "enter a student number";
		}
		else {
			string id((char*)(Marshal::StringToHGlobalAnsi(studentNo->Text)).ToPointer());
			string query = "select id from student, department where id = " + id + " and department.dept_name = student.dept_name and faculty = \"" + FacultyName + "\";";

			int check = mysql_query(con, query.c_str());

			if (!check) {
				MYSQL_RES* res = mysql_store_result(con);
				int count = mysql_num_rows(res);
				if (count == 0) {
					studentError->Text = "incorrect student id or student not in your faculty";
				}
				else {
					if (graduateCheck->Checked == true) {
						query = "select s_id from frozen_student where s_id = " + id + ";";
						check = mysql_query(con, query.c_str());
						if (!check) {
							res = mysql_store_result(con);
							count = mysql_num_rows(res);
							if (count == 0) {
								query = "select s_id from inactive_student where s_id = " + id + ";";
								check = mysql_query(con, query.c_str());
								if (!check) {
									res = mysql_store_result(con);
									count = mysql_num_rows(res);
									if (count == 0) {
										query = "insert into graduated_student values (" + id + ");";
										check = mysql_query(con, query.c_str());
										if (check) {
											studentError->Text = "student is already graduated";
										}
										else {
											query = "update student set status = false where id = " + id + ";";
											mysql_query(con, query.c_str());
											studentError->Text = "updated";
										}
									}
									else {
										studentError->Text = "student is inactive";
									}
								}
							}
							else {
								studentError->Text = "student is frozen";
							}
						}

					}
					else if (inactiveCheck->Checked == true) {
						query = "select s_id from frozen_student where s_id = " + id + ";";
						check = mysql_query(con, query.c_str());
						if (!check) {
							res = mysql_store_result(con);
							count = mysql_num_rows(res);
							if (count == 0) {
								query = "select s_id from graduated_student where s_id = " + id + ";";
								check = mysql_query(con, query.c_str());
								if (!check) {
									res = mysql_store_result(con);
									count = mysql_num_rows(res);
									if (count == 0) {
										query = "insert into inactive_student values (" + id + ");";
										check = mysql_query(con, query.c_str());
										if (check) {
											studentError->Text = "student is already graduated";
										}
										else {
											query = "update student set status = false where id = " + id + ";";
											mysql_query(con, query.c_str());
											studentError->Text = "updated";
										}
									}
									else {
										studentError->Text = "student is graduated";
									}
								}
							}
							else {
								studentError->Text = "student is frozen";
							}
						}

					}

					else if (activateCheck->Checked == true) {
						query = "select s_id from inactive_student where s_id = " + id + ";";
						check = mysql_query(con, query.c_str());
						if (!check) {
							res = mysql_store_result(con);
							count = mysql_num_rows(res);
							if (count == 0) {
								studentError->Text = "student is active";
							}
							else {
								query = "delete from inactive_student where s_id = " + id + ";";
								check = mysql_query(con, query.c_str());
								if (!check) {
									query = "update student set status = true where id = " + id + ";";
									mysql_query(con, query.c_str());
								}
							}
						}
					}

					else if (freezeCheck->Checked == true) {
						query = "select s_id from graduated_student where s_id = " + id + ";";
						check = mysql_query(con, query.c_str());
						if (!check) {
							res = mysql_store_result(con);
							count = mysql_num_rows(res);
							if (count == 0) {
								query = "select s_id from inactive_student where s_id = " + id + ";";
								check = mysql_query(con, query.c_str());
								if (!check) {
									res = mysql_store_result(con);
									count = mysql_num_rows(res);
									if (count == 0) {
										query = "insert into frozen_student values (" + id + ");";
										check = mysql_query(con, query.c_str());
										if (check) {
											studentError->Text = "student is already frozen";
										}
										else {
											query = "update student set status = false where id = " + id + ";";
											mysql_query(con, query.c_str());
											studentError->Text = "updated";
										}
									}
									else {
										studentError->Text = "student is inactive";
									}
								}
							}
							else {
								studentError->Text = "student is graduated";
							}
						}

					}

					else if (unfreezeCheck->Checked == true) {
						query = "select s_id from frozen_student where s_id = " + id + ";";
						check = mysql_query(con, query.c_str());
						if (!check) {
							res = mysql_store_result(con);
							count = mysql_num_rows(res);
							if (count == 0) {
								studentError->Text = "student is not frozen";
							}
							else {
								query = "delete from frozen_student where s_id = " + id + ";";
								check = mysql_query(con, query.c_str());
								if (!check) {
									query = "update student set status = true where id = " + id + ";";
									mysql_query(con, query.c_str());
									studentError->Text = "updated";
								}
							}
						}
					}
					mysql_free_result(res);
				}
			}
		}
	}
}
private: System::Void activateCheck_Click(System::Object^ sender, System::EventArgs^ e) {
	freezeCheck->Checked = false;
	inactiveCheck->Checked = false;
	graduateCheck->Checked = false;
	activateCheck->Checked = true;
	unfreezeCheck->Checked = false;
}
private: System::Void unfreezeCheck_Click(System::Object^ sender, System::EventArgs^ e) {
	freezeCheck->Checked = false;
	inactiveCheck->Checked = false;
	graduateCheck->Checked = false;
	activateCheck->Checked = false;
	unfreezeCheck->Checked = true;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	cordAddStudent^ obj = gcnew cordAddStudent(FacultyName);
	obj->ShowDialog();
}
};
}
