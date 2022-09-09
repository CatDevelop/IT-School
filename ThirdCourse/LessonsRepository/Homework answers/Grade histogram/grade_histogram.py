from tkinter import filedialog
import grade

in_filename = filedialog.askopenfilename()
in_file = open(in_filename)

out_filename = filedialog.asksaveasfilename()
out_file = open(out_filename,'w')

# Read the grades into list
grades = grade.read_grades(in_file)

# Count the grades per range
range_counts = grade.count_grade_ranges(grades)

# Write the histogram to the output file
grade.write_histogram(range_counts, out_file)

in_file.close()
out_file.close()
