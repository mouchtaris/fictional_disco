.. vim: et ts=2 sw=2

=====
CMake
=====

Welcome to perfect cmake.

.. code-block:: cmake

    # vim: et ts=4 sw=4
    #
    # Hello, user.
    #
    # Welcome to Aperture IT.
    #

    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    cmake_minimum_required(VERSION 3.12)



++++++++++++
Constructors
++++++++++++

.. code-block:: cmake

  add_executable()
  add_library()



++++++++++++++++
Member variables
++++++++++++++++



++++++++++++++++
Member functions
++++++++++++++++

.. code-block:: cmake

  get_target_property()
  set_target_properties()
  get_property(TARGET)
  set_property(TARGET)
  target_compile_definitions()
  target_compile_features()
  target_compile_options()
  target_include_directories()
  target_link_libraries()
  target_sources()

  target_compile_features(Foo     # Add to target properties...
    PUBLIC
      cxx_strong_enum             # =>  COMPILE_FEATURES
    PRIVATE                       #     INTERFACE_COMPILE_FEATURES
      cxx_lambdas                 # =>  COMPILE_FEATURES
      cxx_range_for
  )

  target_link_libraries(Foo
    PUBLIC Bar::Bar               # => {INTERFACE_,}LINK_LIBRARIES
                                  # INTERFACE_<property> of Bar::Bar 
                                  #   => {INTERFACE),}<property> of Foo
    PRIVATE Cow::Cow              # => LINK_LIBRARIES
                                  # INTERFACE_<property> of Cow::Cow
                                  #   => <property> of Foo
  )

