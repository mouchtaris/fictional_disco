# vim: et ts=2 sw=2

module Sagas
  def saga_line(&block : Proc(String))
    LineAdder.new(block)
  end

  def saga_empty_body
    [
      (saga_line { "{" }),
      (saga_line { "}" }),
    ]
  end

  def saga_warn_autogenerated_begin
    [
      (saga_line { "// SMS:autogenerated_begin" }),
    ]
  end

  def saga_warn_autogenerated_end
    [
      (saga_line { "// SMS:autogenerated_end" }),
    ]
  end

  def saga_include_header(name)
    [
      (saga_line { "#include \"#{name}.h\"" }),
    ]
  end

  def saga_empty_line
    [
      (saga_line { "" }),
    ]
  end

  def saga_close_modspace
    [
      (saga_line { "}" }),
    ]
  end
end
