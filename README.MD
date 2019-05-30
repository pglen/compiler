# Compiler studies

## pcomp - parallel compiler

     Quick intro --- teaser, see SYNTAX

 	Types:

		u8; u16; u32; 				; Unsigned integers
		s8; s16; s32; 				; Signed integers

		single,	double				; Floating point types

	Custom types:

		type_name					; declared by struct statement


 Exceptions:

		The kill exception terminates the application by default.
		Other exceptions set (increment) the appropriate exception variable,
		(excpt) and return without any action.
		It is the application's responsibility to respond to the exception
		condition by checking the variable against a saved value.
		The exception variable is not reset automatically.

 Expressions:

		Expressions are evaluated much like in 'C'. New operators are introduced,
		and the order of precendece follows industrial conventions.
		The operators are obeying the signed / unsigned interpretation
		of variables, in case the oparator sign-nesses are in conflict,
		the compiler reports an error.

 Type conversions:

		Casting not required upwards, to larger storage size. Size promotion
		is automatic.



