program fortBinding
use iso_c_binding, only: C_CHAR, C_DOUBLE, C_NULL_CHAR, C_INT, C_PTR
implicit none
interface 
  function yaml_event_reader(filePath) bind(C, name="yamlEventReader")
    use iso_c_binding, only: c_char, c_ptr
    character(kind=c_char) :: filePath(*)
    type(c_ptr) :: yaml_event_reader
  end function yaml_event_reader 

  function get_var_for_comp(dict, comp_num, var_name, sys_name) bind(C, name="get_var_for_comp_c")
    use iso_c_binding, only: c_char, c_double, c_int, c_ptr
    type(c_ptr), value :: dict
    integer(c_int) :: comp_num
    character(kind=c_char) :: var_name, sys_name
    real(c_double) :: get_var_for_comp
  end function get_var_for_comp
end interface

!! Pointer to the C++ Dictionary
type(c_ptr) :: dict_ptr

real(c_double) :: des_fact

!! Not currently supporting global tags
!character(kind=c_char, len=*), parameter :: gtag_file = "../yamlFiles/global-tag.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: nYaml_file = "../yamlFiles/nYaml.yaml" // c_null_char

!call yaml_event_reader
dict_ptr = yaml_event_reader(nYaml_file) 

! Get some design factors
des_fact = get_var_for_comp(dict_ptr, 105, "friction_design_factor", "LOCCA_INJECTION")
write(*,*) des_fact

end program 
