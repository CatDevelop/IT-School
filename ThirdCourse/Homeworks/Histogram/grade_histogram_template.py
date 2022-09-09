from tkinter import filedialog
#import grade_template
from grade_template import read_grades
from grade_template import count_grade_ranges
from grade_template import write_histogram

in_filename = filedialog.askopenfilename()
in_file = open(in_filename)

out_filename = filedialog.asksaveasfilename()
out_file = open(out_filename,'w')

grades_list = read_grades(in_file)
count_array = count_grade_ranges(grades_list)
write_histogram(count_array, out_file)