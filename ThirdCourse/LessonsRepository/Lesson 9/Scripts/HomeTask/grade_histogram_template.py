from tkinter import filedialog
import grade_template

in_filename = filedialog.askopenfilename()
in_file = open(in_filename)

out_filename = filedialog.asksaveasfilename()
out_file = open(out_filename,'w')

# Read the grades into list

# Count the grades per range

# Write the histogram to the output file