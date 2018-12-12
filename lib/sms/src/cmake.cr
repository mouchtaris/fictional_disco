# vim: et ts=2 sw=2

module CMake
  @io : IO
  include ConfDirViews

  private def skeletor
    conf_skeletor.subconf("CMakeLists.txt")
  end

  def write(line)
    @io.puts line
  end

  def write_skel(name)
    skeletor.lines(name).each { |l| write l }
  end

  def add_executable(name)
    write "add_executable(#{name})"
  end

  def add_library(name)
    write "add_library(#{name})"
  end

  def target_source(target, source)
    write "target_sources(#{target} PRIVATE #{source})"
  end

  def target_link_libraries(target, libr, style = "PRIVATE")
    write "target_link_libraries(#{target} #{style} #{libr})"
  end

  def target_compile_definitions(target, defin, style = "PRIVATE")
    write "target_compile_definitions(#{target} #{style} #{defin})"
  end

  def target_compile_options(target)
    target_link_libraries target, "_compile_options"
  end

  def header
    write_skel :header
  end

  def call
    header

    add_library :lib
    target_compile_options :lib
    target_source :lib, "src/lib.cpp"

    add_executable :main
    target_compile_options :main
    target_source :main, "src/main.cpp"
    target_link_libraries :main, :lib

    add_executable :test
    target_compile_options :test
    target_source :test, "test/main.cpp"
    target_link_libraries :test, :lib

    conf_mods.each do |mod_name, mod|
      target_source :main, "src/#{mod_name}.cpp"
      target_source :test, "test/test_#{mod_name}.cpp"

      comp_list = mod.subconf(:comps).list
      sacls = comp_list.join(", ")
      target_compile_definitions :main, "#{mod_name.upcase}__SACLS=\"#{sacls}\""

      comp_list.each do |comp|
        target_source :main, "src/#{mod_name}/#{comp}.cpp"
        target_source :test, "test/#{mod_name}/test_#{comp}.cpp"
      end
    end
  end
end
