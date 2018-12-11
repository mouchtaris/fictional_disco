# vim: et ts=2 sw=2

module CMake
  @io : IO
  @conf : ConfDirStorage

  private def skeletor
    @conf.subconf(:skeletor).subconf("CMakeLists.txt")
  end

  def header
    skeletor.list(:header).each { |l| @io.puts l }
  end

  def target_main
    @io.puts "add_executable(main)"
  end

  def target_test
    @io.puts "add_executable(test)"
  end

  def call
    header
    target_main
    target_test
  end
end
