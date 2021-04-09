program fortBinding
use iso_c_binding, only: C_CHAR, C_DOUBLE, C_NULL_CHAR, C_INT, C_PTR, C_DOUBLE
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
   integer(C_INT) :: number
   real(C_DOUBLE) :: friction_design_factor
   real(C_DOUBLE) :: interfactial_design_factor
   real(C_DOUBLE) :: design_factor1
   real(C_DOUBLE) :: design_factor2
   real(C_DOUBLE) :: design_factor3
   real(C_DOUBLE) :: design_factor4
   real(C_DOUBLE) :: design_factor5
   character(kind=C_CHAR, len=72) :: system  
end type Component   

type(Component) :: volume_g ! wants only global design factor
type(Component) :: volume_sys ! wants only system design factor
type(Component) :: volume_loc ! wants only local design factor
type(Component) :: volume_sys_loc ! wants system and local
type(Component) :: volume_g_loc ! wants global and local
type(Component) :: volume_g_sys ! wants global and system
type(Component) :: volume_g_sys_loc ! want global system and local
!character(kind=c_char, len=*), parameter :: gtag_file = "../yamlFiles/global-tag.yaml" // c_null_char !! Not currently supporting
!global tags

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

des_fact = get_var_for_comp(dict_ptr, 105, "friction_design_factor", "LOCCA_INJECTION")
write(*,*) des_fact
character(kind=c_char, len=*), parameter :: nYaml_file = "../yamlFiles/nYaml.yaml" // c_null_char

volume_g%number=100
volume_sys%number=111
volume_sys%system="Primary"
volume_loc%number=122
volume_loc%design_factor5 = 33.333
volume_sys_loc%number=200
volume_sys_loc%system="Secondary"
volume_g_loc%number=300
volume_g_sys%number=400
volume_g_sys%system="LOCCA"
volume_g_sys_loc%number=500
volume_g_sys_loc%system="Primary"
!call yaml_event_reader(gtag_file) 

end program fortBinding  

!function isPartofSystemName(comp%system, arg) result(tf)
!    character(kind=c_char, len=*) :: arg ! from cpp dictionary
!    character(len=*) :: comp%system      ! from fortran structure
!    logical :: tf ! true or false
!
!    tf = arg == comp%system
!
!end function
