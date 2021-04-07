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
    integer(c_int), value :: comp_num
    character(kind=c_char) :: var_name, sys_name
    real(c_double) :: get_var_for_comp
  end function get_var_for_comp
end interface

!! Pointer to the C++ Dictionary
type(c_ptr) :: dict_ptr

real(c_double) :: des_fact
type Component
   integer :: number
   real :: friction_design_factor
   real :: interfactial_design_factor
   real :: design_factor1
   real :: design_factor2
   real :: design_factor3
   real :: design_factor4
   real :: design_factor5
   character(len=72) :: system
end type Component   

type(Component) :: volume_Global
type(Component) :: volume_System
type(Component) :: volume_Local
!! Not currently supporting global tags
!character(kind=c_char, len=*), parameter :: gtag_file = "../yamlFiles/global-tag.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: nYaml_file = "../yamlFiles/nYaml.yaml" // c_null_char

!call yaml_event_reader
dict_ptr = yaml_event_reader(nYaml_file) 

! Get some design factors
des_fact = get_var_for_comp(dict_ptr, 102, "friction_design_factor", "" // c_null_char)
write(*,*) des_fact, " should be 1.13"
des_fact = get_var_for_comp(dict_ptr, 102, "friction_design_factor", "Secondary" // c_null_char)
write(*,*) des_fact, " should be 1.13"
des_fact = get_var_for_comp(dict_ptr, 102, "friction_design_factor", "Primary" // c_null_char)
write(*,*) des_fact, " should be 2.8"
des_fact = get_var_for_comp(dict_ptr, 104, "friction_design_factor", "Primary" // c_null_char)
write(*,*) des_fact, " should be 1.23"
des_fact = get_var_for_comp(dict_ptr, 105, "friction_design_factor", "Primary" // c_null_char)
write(*,*) des_fact, " should be 2.23"
des_fact = get_var_for_comp(dict_ptr, 106, "friction_design_factor", "Primary" // c_null_char)
write(*,*) des_fact, " should be 2.2354343"
des_fact = get_var_for_comp(dict_ptr, 107, "friction_design_factor", "Primary" // c_null_char)
write(*,*) des_fact, " should be 2.2354343"
des_fact = get_var_for_comp(dict_ptr, 108, "friction_design_factor", "Primary" // c_null_char)
write(*,*) des_fact, " should be 2.2354343"
des_fact = get_var_for_comp(dict_ptr, 108, "jimbob", "Primary" // c_null_char)
write(*,*) des_fact, " should be 1.0"


end program 
