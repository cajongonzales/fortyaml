program fortBinding
use iso_c_binding, only: C_CHAR, C_NULL_CHAR, C_INT
implicit none
interface 
  subroutine print_c(string) bind(C, name="print_C")
    use iso_c_binding, only: c_char
    implicit none
    character(kind=c_char) :: string(*)
  end subroutine print_c

  subroutine yaml_parser(int_argc, fort_argv) bind(C, name="yamlParser")
  !subroutine yaml_parser(int_argc) bind(C, name="yamlParser")
    use iso_c_binding, only: c_char, c_int
    integer(kind=c_int), value :: int_argc
    character(kind=c_char) :: fort_argv(*)
  end subroutine yaml_parser
  subroutine yaml_event_reader(filePath) bind(C, name="yamlEventReader")
    use iso_c_binding, only: c_char
    character(kind=c_char) :: filePath(*)
  end subroutine yaml_event_reader 
!  subroutine pass_int(aa) bind(C, name="passInt")
!    use iso_c_binding, only: C_INT
!    implicit none
!    integer(c_int) :: aa
!  end subroutine pass_int
end interface

integer :: fort_argc
character(kind=c_char, len=*), parameter :: input_file = "anchors.yaml" 
!character(kind=c_char, len=*), parameter :: file_path = "../yamlFiles/public.yaml"
character(kind=c_char, len=*), parameter :: file_path = "../yamlFiles/nYaml.yaml"

!call print_c(C_CHAR_"Hello World from C"//C_NULL_CHAR)
!call print_c(c_string//C_NULL_CHAR)

!call pass_int(fort_argc);

!fort_argc = 2
!call yaml_parser(fort_argc, C_CHAR_"test.yaml"//C_NULL_CHAR)

!call yaml_parser(fort_argc, input_file)

call yaml_event_reader(file_path) 
end program 
